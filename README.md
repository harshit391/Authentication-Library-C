
# Authentication System in C

An Authentication System library in C that provides a static library for seamless integration into any C program. It includes features like password hashing and user management with MongoDB, allowing users to implement authentication without needing to understand the underlying library details.

---

## Index 
1. [Key Features](#key-features-of-auth-library-created-by-this-program)
2. [Pre Requisites](#pre-requisites)
3. [Libraries Used](#libraries-used)
4. [Data Base](#data-base)
5. [Setting Up Project](#setting-up-the-project)
6. [Using The Library You Created](#what-singhautha-provides-you)
7. [Setting Up Mongo DB](#setup-mongo-db)
8. [Final Remarks](#)

---

### Key Features of Auth Library Created by This Program:

- **User Registration:** Secure and intuitive process for creating new user accounts.
- **Login System:** Efficient login mechanism with secure password verification.
- **Password Management:** Password encryption using Encoding Algorithms.
- **Input Validation:** Prevents buffer overflows and other security vulnerabilities.
- **Scalable Design:** Easy integration into larger systems or applications.
- **Cross Platform:** The Creation of a Static Library help users to access the authentication even without installing external unix libraries

***

### Pre Requisites

**1. Linux System**  
The libraries required to make this Auth System work are easily available in Linux, whereas Windows needs quite a process to make those libraries work.

**2. A Gmail Account (Optional)**  
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
- For Cloud Instance
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

###### Estimated Time Complexity:

The time complexity of a brute-force attack on this encoding function can be estimated as:

\[
O(95^n)
\]

where \(n\) is the password length. Even for relatively short passwords (e.g., 8 characters), the complexity is \(95^8\), which is over 6.6 trillion possible combinations.

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

4. You will be getting ```SinglaAuth.a``` file and Now Just compile your C Program by simply
```bash
gcc file.c -L. singlaAuth.a -o file
```

5. And Run Your Program by
```bash
./file
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
bool decode(char dbpassword[], char userpassword[])
```
- It will basically provide the Boolean value  as true or false whether the user entered password matches to the data base stored password of that user or not.

**7. Generate Code**
```c
void generate_verf_code(char output[], int n)
```
- Take n as a input and generate n - 1 length Random Integer Code and store it in the output array

**8. Get Data From File**
```c
void getDataFromFile(char output[], char filePath[])
```
- To Retrive a String Content from a Text File

**9. Insert User in Data Base**
```c
void insertDB(char name[], char email[], char password[])
```
- If Everything is valid It will insert the Data into Database
- It is being assumed while using this Function is that You have already validated the Name Email and Password to be non Empty and Correct fields

**10. Send Mail of a Verification Code You Already Generated**
```c
int sendMail(char recipient[], char verficicationCode[])
```
- It will Return 0 if everything is good

**11. Check If User Exists**
```c
int userExists(char email[])
```
- Return 1 If User Already exists in DataBase
- Return 0 If User Not Exists

**12. Retrieve Hashed Password from Database of User**
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

### Final Remarks

I Hope this will help you to have authentication feature in your C Programs with as ease as possible

[Connect on Linked for Feedback](https://www.linkedin.com/in/harshitsingla1761/) 