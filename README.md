
# Authentication Library in C

![Intro](./readme/Authentication.png)

An Authentication System library in C that provides a static library for seamless integration into any C program. It includes features like password hashing and user management with MongoDB, allowing users to implement authentication without needing to understand the underlying library details.

---

#### Compatibility - Linux/Unix Operating System
![Linux](./readme/linux.jpg)

---

## Index 
1. [Key Features](#key-features-of-auth-library-created-by-this-program)
2. [Pre Requisites](#pre-requisites)
3. [Libraries Used](#libraries-used)
4. [Data Base and Hashing Algorithm](#data-base)
5. [Want to Get a Pre-Built Library](#want-to-use-pre-built-library)
6. [Setting Up Project](#setting-up-the-project)
7. [Using The Library You Created](#what-singhautha-provides-you)
8. [Setting Up Mongo DB](#setup-mongo-db)
9. [Singla Hashing - Time Complexity for Brute Force Attack](#estimated-time-complexity-for-brute-force-attack-on-singla-hash)
9. [Future Scope](#future-scope)
10. [Final Remarks](#future-scope)

---

### Key Features of Auth Library Created by This Program:

- **User Registration:** Secure and intuitive process for creating new user accounts.
- **Login System:** Efficient login mechanism with secure password verification.
- **Password Encryption:** Password encryption using Encoding Algorithms.
- **Input Validation:** Prevents buffer overflows and other security vulnerabilities.
- **Static Library:** Easy integration into larger systems or applications by creating a static library for whole system
- **Cloud Database:** Seamlessly connects to a cloud database for storing user information and credentials.

***

### Pre Requisites

**1. Linux System**  
The libraries required to make this Auth System work are easily available in Linux, whereas Windows needs quite a process to make those libraries work.

**2. A Gmail Account**  
I guess everyone has one Gmail account. This is only required to have an App Password to use your mail account externally.

- Go to [Create App Password](https://myaccount.google.com/apppasswords).
- Generate an App Password.
- Take note of it in Notepad or wherever you want.

**3. MongoDB Account**
A Mongo Account whether its of Cloud-Atlas or Its Local Just a Valid Mongo URL directly pointing towards the collection you need It will look like this

- For Local Instance
```text
mongodb://localhost:27017/testdb
```
- For Cloud Instance (My Recommendation)
```text
mongodb+srv://username:password@clusterurl/?retryWrites=true&w=majority&appName=insertDB-example
```
- Don't Worry You will get the URL from Terminal for Local and Atlas will provide you the url for Cloud Account

- Further You can Use [MongoDB Setup](#setup-mongo-db) Section of this Read Me to Create Mongo DB Account for Local and Cloud

**3. Setup**
- Okay So This is the only Requirement because all the libraries that need to be installed are mentioned in         ```Linux-Setup.sh``` File 
- Just Run the ```Linux-Setup.sh``` file in your linux Terminal by
```bash
./Linux-Setup.sh
```
- You will be asked for Several Details Which I hope you noted already as I mentioned above
- It Includes Google Email, App Password and MongoDB URL

**4. Congratualtions**
- Setup is Complete Now You can Test The Files using Test Files If its working with your credential
- After You are Satisfied Just Run ``Auth-Setup.sh`` file in your Linux Terminal to Create a Static Library
```bash
./Auth-Setup.sh
```
---

### Libraries Used
*1. External Libraries*
- **libmongoc-dev :-** Mongo DB C Driver 
- **libcurl4-openssl-dev** - Client URL Request Driver for Mail
- **pkg-config :-** Configuration of Mongo DB C Driver to work without errors

*2. Unix Libraries*
- **errno.h**
- **limits.h**
- **time.h**
- **fcntl.h**
- **unistd.h**
- **sys/stat.h**
- **sys/time.h**

---

### Data Base
MongoDB is used to store the user databas which includes
1. Name of the user
2. Email of the user ( Should be Unique )
3. Password 

Password is well encrypted by help of a fun type personally designed algorithm named Singla Hashing 

##### Singla Hashing 
- It uses Mathematical Operations with use of 3 Private Secret Keys and 1 Public Key
- Of course you can change any of them or Like just use whatever already exists
- To analyze the complexity of brute-forcing the hashing algorithm you've implemented, we need to consider several aspects of the encoding process:

---
### Want to Use Pre-Built Library

- You can use my provided singlaAuth.a
- The Keys used in this are totally different which are being provided as an example in previous commits
- Now the used values are more secure
- Just Compile your Program as Mentioned [Below](#setting-up-the-project)

---
### Setting up the Project 
1. Clone the Repo by 
```bash
git clone https://github.com/harshit391/Authentication-System-C.git
```
2. First Run the ```Linux-Setup.sh``` Shell File
```bash
./Linux-Setup.sh
```
3. Then Run the ```app.sh``` Shell File
```bash
./Auth-Setup.sh
```

4. You will be getting ```singlaAuth.a``` and ```singlaHash.a``` is already present in hash folder, So Now Just compile your C Program by simply
```bash
gcc App.c -L. singlaAuth.a hash/singlaHash.a -o singla-auth $(pkg-config --cflags --libs libmongoc-1.0) -lcurl
```

5. And Run Your Program by
```bash
./singla-auth
```

---
### What SinghAuth.a Provides you

**1. Login Function**
- The Login Function will be looking like
```c
void login()
```
- When You call the function It automatically takes User Input for Email and Password and Checks If User is Authenticated
- It will not return anything as its quite a challenge to perform token authentication in c But You can modify it as your will

**2. SignUp Function**
- The Sign Up Function will look like
```c
void signup()
```
- When you call the function it automatically takes User Input for Name, Email and Password
- If You Email is valid you will get Verification Email
- You get 5 tries to validate the code If failed you have to restart the program
- After validating everything It will acknowledge that User is saved in you Data Base

**3. Reset Password**
```c
void resetPass(char email[])
```
- It will send the user a verification Code Email
- If Valid User He/She can Reset their user Passoword

**4. Create And Hash Password**
```c
void enterAndHashPassword(char output[])
```
- Automatically Takes Password as input and return the output encoded value in the output array

**5. Encode**
```c
void encode(char input[], char output[])
```
- Client Provides the Input and It will give the encoded value in the output array

**6. Decode**
```c
void decode(char dbpassword[], char output[])
```
- It will store the decoded value of hashed value in the output character array

**7. Compare**
```c
bool compare(char dbpassword[], char userpassword[])
```
- It will basically provide the Boolean value  as true or false whether the user entered password matches to the data base stored password of that user or not.

**8. Generate Code**
```c
void generate_verf_code(char output[], int n)
```
- Take n as a input and generate n - 1 length Random Integer Code and store it in the output array

**9. Get Data From File**
```c
void getDataFromFile(char output[], char filePath[])
```
- To Retrive a String Content from a Text File

**10. Insert User in Data Base**
```c
void insertDB(char name[], char email[], char password[])
```
- If Everything is valid It will insert the Data into Database
- It is being assumed while using this Function is that You have already validated the Name Email and Password to be non Empty and Correct fields

**11. Update Password of a User in Data Base**
```c
void updateUser(char email[], char newPass[])
```
- If Everything is valid It will Update the Password Data into Database for User with value of parameter email
- It is being assumed while using this Function is that You have already validated the Name Email and Password to be non Empty and Correct fields

**12. Send Mail of a Verification Code You Already Generated**
```c
int sendMail(char recipient[], char verficicationCode[])
```
- It will Return 0 if everything is good

**13. Check If User Exists**
```c
bool userExists(char email[])
```
- Return 1 If User Already exists in DataBase
- Return 0 If User Not Exists

**14. Retrieve Hashed Password from Database of User**
```c
void getPassword(char email[], char output[], size_t passwordSize)
```
- It will Retrieve the password stored for User with Email in Data Base
- It will be a hashed Password stored in Output file
- Password Size you can give like 100 or 50 Doesn't matter because Its Just to Ensure the overflow Condition Doesn't Occur


---

### Setup Mongo DB

**1. In Local**
- [Dowload MongoDB For Local](https://www.mongodb.com/try/download/community)
- Add Path in Enviornment Variables
```text
C:\Program Files\MongoDB\Server\7.0\bin
```
- Plase Replace 7.0 with your Current Version
- [Download Mongo Shell ( CLI )](https://www.mongodb.com/try/download/shell)
- Add Path in Environment Variables
```text
C:\Program Files\mongosh-2.2.2-win32-x64\bin
```
- Just Add the Path where mongosh folder is located
- Now Open Terminal And Type
```bash
mongosh
```
- It will open the Mongo Shell
- Copy the Initial URL which looks like
```text
mongodb://127.0.0.1:27017/
```
- Note it to Use in the Auth Library

**2. In Atlas Cloud**
- [Create Account Here](https://account.mongodb.com/account/login)
- Click on Project 0 at Top Left Corner and Click Create New Project
- Select Free Cluster or Depends on Your Choice and Don't Change Anything
- You will be given username and Password to access that databse Note it
- Click on Create Database User
- Go to Network Access in 1st Point
- Click on Add IP Address and Tap on Allow Access from Anywhere ( Just for Development Purposes )
- Close The Tab and Click Choose a Connection Method 
- Go To Drivers
- Select C
- Enable Show password in URL and Make a Note of that URL 
- Just Click on Done!
- Now Go To Browse Collections 
- Delete any sample collection
- And You are Done Here to Use your Mongo Database

---

### Estimated Time Complexity for Brute Force Attack on Singla Hash:

#### Case 1: General Encoding Function

For a brute-force attack on this encoding function, the time complexity is estimated as:

\[ 3 \times 95^n + 2^{32} \]
Written as: 
\[ O(95^n) \]

- **Short Passwords (4-6 characters):** Billions to trillions of combinations (1 Arab to 1 Kharab). Potentially crackable but time-consuming.
- **Medium-Length Passwords (7-10 characters):** Quintillions to septillions of combinations, making brute-force attacks extremely challenging.
- **Long Passwords (11+ characters):** Astronomical combinations (decillions and beyond). Brute-force attacks are practically infeasible.

Each additional character increases complexity by a factor of 95, leading to exponential growth in difficulty.

#### Case 2: Using Lookup Tables

With public lookup tables, the time complexity is reduced to:

\[ 95^n + 2^{32} \]
Written as: 
\[ O(95^n) \]

- **Short Passwords (4-6 characters):** Ranges from 10^33 to 10^35 combinations (1 decillion to 100 decillion). Still extremely challenging but more feasible.
- **Medium-Length Passwords (7-10 characters):** Ranges from 10^36 to 10^39 combinations (1 undecillion to 1 duodecillion). Requires millions to billions of years to crack.
- **Long Passwords (11+ characters):** Over 10^40 combinations (10 duodecillion and beyond). Nearly impossible to crack with current technology.

Even with known lookup tables, passwords of 8 characters or more remain highly secure against brute-force attacks.

---

### Future Scope

- Compatibility With Windows
- GUI 
- Token Generation and Authentication
- Integration with Windows SSO

---

### Final Remarks

I Hope this will help you to have authentication feature in your C Programs with as ease as possible

[Connect on Linked for Feedback](https://www.linkedin.com/in/harshitsingla1761/) 

---