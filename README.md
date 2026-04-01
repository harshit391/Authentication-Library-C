
# Authentication Library in C

![Intro](./readme/Authentication.png)

A static authentication library in C that provides user registration, login, and password reset out of the box. It handles password hashing (custom Singla Hashing algorithm), email verification via Gmail SMTP, and user storage in MongoDB — so you can add authentication to any C program by linking a single `.a` file and calling a few functions.

---

## Table of Contents

1. [Features](#features)
2. [Architecture](#architecture)
3. [Prerequisites](#prerequisites)
4. [Getting Started](#getting-started)
   - [Linux (Native)](#linux-native)
   - [Docker (Any OS)](#docker-any-os)
5. [API Reference](#api-reference)
   - [High-Level Functions](#high-level-functions)
   - [Hashing Functions](#hashing-functions)
   - [Database Functions](#database-functions)
   - [Utility Functions](#utility-functions)
6. [Project Structure](#project-structure)
7. [MongoDB Setup](#mongodb-setup)
8. [Security](#security)
9. [Brute Force Complexity](#brute-force-complexity)
10. [Future Scope](#future-scope)

---

## Features

- **User Registration** — name, email, and password with email format validation
- **Login** — password verification with a 5-attempt lockout
- **Password Reset** — email-verified password change flow
- **Email Verification** — 6-digit codes sent via Gmail SMTP with TLS
- **Password Hashing** — custom Singla Hashing algorithm (3 private keys + 1 public key)
- **MongoDB Storage** — cloud or local, with TLS-secured connections
- **Static Library** — link `singlaAuth.a` + `singlaHash.a` into any C program
- **Docker Support** — run on any OS without installing Linux dependencies

---

## Architecture

```
App.c (CLI Menu)
 |
 |-- [1] Login    --> pages/login.h
 |       |-- userExists()            (MongoDB lookup)
 |       |-- getPassword()           (retrieve hashed password)
 |       \-- compare()               (verify via singlaHash.a)
 |
 |-- [2] Signup   --> pages/signUp.h
 |       |-- checkEmail()            (format validation)
 |       |-- userExists()            (duplicate check)
 |       |-- enterAndHashPassword()  (hash via singlaHash.a)
 |       |-- generate_verf_code()    (random 6-digit code)
 |       |-- sendMail()              (Gmail SMTP)
 |       \-- insertUser()            (MongoDB insert)
 |
 \-- [3] Reset    --> pages/reset.h
         |-- userExists()
         |-- generate_verf_code() + sendMail()
         |-- enterAndHashPassword()
         \-- updateUser()            (MongoDB update)
```

**Database Schema (MongoDB):**

```json
{
  "name": "string",
  "email": "string (unique)",
  "password": "string (Singla-hashed)"
}
```

---

## Prerequisites

### 1. Gmail App Password

Required for sending verification emails.

1. Go to [Google App Passwords](https://myaccount.google.com/apppasswords)
2. Generate an App Password
3. Save it — you will need it during setup

### 2. MongoDB

A valid MongoDB connection URI pointing to your database. Either:

- **Local:**
  ```
  mongodb://localhost:27017/testdb
  ```
- **Atlas Cloud (recommended):**
  ```
  mongodb+srv://<username>:<password>@<cluster>.mongodb.net/?retryWrites=true&w=majority
  ```

See the [MongoDB Setup](#mongodb-setup) section for step-by-step instructions.

### 3. Linux or Docker

- **Native:** Linux/Unix system (Ubuntu, Debian, etc.)
- **Any OS:** Docker Desktop (Windows, macOS, Linux)

---

## Getting Started

### Linux (Native)

```bash
# 1. Clone the repository
git clone https://github.com/harshit391/Authentication-Library-C.git
cd Authentication-Library-C

# 2. Run the setup script (installs gcc, libmongoc, libcurl, pkg-config)
#    You will be prompted for: project path, Gmail, App Password, MongoDB URI
./Linux-Setup.sh

# 3. Build the static library
./Auth-Setup.sh

# 4. Compile and run
gcc App.c -L. singlaAuth.a hash/singlaHash.a -o singla-auth \
    $(pkg-config --cflags --libs libmongoc-1.0) -lcurl
./singla-auth

# Or simply:
./app.sh
```

### Docker (Any OS)

No Linux system required. Docker handles all dependencies.

**Using `docker run`:**

```bash
# Build the image
docker build -t singla-auth .

# Run interactively with your credentials
docker run -it \
  -e MONGO_URI='<your-mongodb-uri>' \
  -e MAIL_USER='you@gmail.com' \
  -e MAIL_PASS='your-app-password' \
  singla-auth
```

**Using `docker compose`:**

```bash
# Create a .env file
cat > .env << 'EOF'
MONGO_URI=<your-mongodb-uri>
MAIL_USER=you@gmail.com
MAIL_PASS=your-app-password
EOF

# Build and run
docker compose run singla-auth
```

> **Note:** The pre-compiled `singlaHash.a` targets x86_64 Linux. The Dockerfile is pinned to `linux/amd64` and will run via emulation on ARM machines (e.g., Apple Silicon).

---

## API Reference

### High-Level Functions

These are the main functions most users will need:

#### `void login()`

Interactive login flow. Prompts for email and password, verifies against the database. Allows 5 password attempts before exiting.

#### `void signup()`

Interactive registration flow. Prompts for name, email, and password. Validates email format, checks for duplicates, sends a verification code via email, and inserts the user into MongoDB on success.

#### `void resetPass()`

Interactive password reset flow. Prompts for email, sends a verification code, and updates the password in MongoDB on successful verification.

---

### Hashing Functions

#### `void enterAndHashPassword(char output[])`

Prompts the user for a password and stores the hashed result in `output`.

#### `void encode(char input[], char output[])`

Hashes `input` and stores the result in `output`.

#### `void decode(char dbpassword[], char output[])`

Decodes a hashed value and stores the result in `output`.

#### `bool compare(char dbpassword[], char userpassword[])`

Returns `true` if the user-entered password matches the stored hashed password.

---

### Database Functions

#### `void insertUser(char name[], char password[], char email[])`

Inserts a new user document into MongoDB. Assumes all fields are validated and the password is already hashed.

#### `void updateUser(char email[], char newPass[])`

Updates the password field for the user matching `email`. Assumes `newPass` is already hashed.

#### `bool userExists(char email[])`

Returns `true` if a user with the given email exists in the database.

#### `void getPassword(char email[], char output[], size_t passwordSize)`

Retrieves the hashed password for the user matching `email` and copies it into `output` (up to `passwordSize - 1` bytes).

---

### Utility Functions

#### `int sendMail(char recipient[], char verificationCode[])`

Sends a verification email to `recipient` containing `verificationCode`. Returns `0` on success.

#### `void generate_verf_code(char output[], int n)`

Generates a random numeric code of length `n - 1` and stores it in `output` (null-terminated).

#### `void getDataFromFile(char output[], char filePath[])`

Reads the contents of a text file at `filePath` into `output`.

---

## Project Structure

```
Authentication-Library-C/
|-- App.c                     Main entry point (interactive CLI menu)
|-- singlaheader.h            Central header (libraries + project includes)
|-- singlaAuth.a              Pre-built static library
|-- hash/
|   \-- singlaHash.a          Pre-compiled hashing library (x86_64)
|-- pages/
|   |-- login.h               Login flow
|   |-- signUp.h              Registration flow with email validation
|   \-- reset.h               Password reset flow
|-- database/
|   |-- src/
|   |   |-- userExists.h      MongoDB user lookup + password retrieval
|   |   |-- insertDB.h        MongoDB insert + update operations
|   |   \-- sendmail.h        Gmail SMTP email sending via cURL
|   |-- utils/
|   |   |-- getData.h         File I/O utilities
|   |   \-- generateCode.h    Random verification code generator
|   \-- files/                Runtime config (gitignored)
|       |-- mongouri.txt      MongoDB connection string
|       |-- mailuser.txt      Gmail address
|       \-- mailpass.txt      Gmail app password
|-- Linux-Setup.sh            Dependency installer + credential setup
|-- Auth-Setup.sh             Static library builder
|-- app.sh                    Compile + run script
|-- Dockerfile                Docker build definition
|-- docker-entrypoint.sh      Docker runtime config from env vars
|-- docker-compose.yml        Docker Compose service definition
\-- .dockerignore             Docker build context exclusions
```

---

## MongoDB Setup

### Local Instance

1. [Download MongoDB Community Server](https://www.mongodb.com/try/download/community)
2. Add the bin directory to your PATH:
   ```
   /usr/bin/mongod   (Linux)
   ```
3. [Download MongoDB Shell](https://www.mongodb.com/try/download/shell)
4. Start the shell:
   ```bash
   mongosh
   ```
5. Copy the connection URL (default: `mongodb://127.0.0.1:27017/`)

### Atlas Cloud (Recommended)

1. [Create an account](https://account.mongodb.com/account/login)
2. Create a new project and select the **Free** cluster tier
3. Create a database user (note the username and password)
4. Go to **Network Access** and click **Allow Access from Anywhere**
5. Go to **Connect** > **Drivers** > select **C**
6. Copy the connection string (enable "Show password" in the URL)
7. Delete any sample collections in **Browse Collections**

---

## Security

- **Passwords** are never stored in plaintext — always hashed with the Singla Hashing algorithm before database storage
- **Email verification** uses random 6-digit codes with a 5-attempt limit
- **TLS encryption** on both MongoDB connections and SMTP email delivery
- **Bounded input** — all `scanf` calls use field-width specifiers to prevent buffer overflows
- **Secrets** are stored in gitignored config files (native) or passed via environment variables (Docker) — never baked into the image

---

## Brute Force Complexity

The Singla Hashing algorithm uses mathematical operations with 3 private secret keys and 1 public key.

### General Encoding

Time complexity for brute force: **O(95^n)**

| Password Length | Combinations     | Feasibility                  |
|-----------------|------------------|------------------------------|
| 4-6 characters  | ~10^8 to ~10^12  | Time-consuming but possible  |
| 7-10 characters | ~10^14 to ~10^20 | Extremely challenging        |
| 11+ characters  | 10^22+           | Practically infeasible       |

### With Known Lookup Tables

Reduced to **O(95^n)** with a smaller constant factor, but passwords of 8+ characters still require millions to billions of years to crack with current hardware.

Each additional character increases difficulty by a factor of 95.

---

## Future Scope

- Token generation and session authentication
- GUI interface
- Integration with system-level SSO
- Support for additional database backends

---

## Connect

[Harshit Singla on LinkedIn](https://www.linkedin.com/in/harshitsingla1761/)
