
# Authentication System in C

An Authentication System library in C that provides a static library for seamless integration into any C program. It includes features like password hashing and user management with MongoDB, allowing users to implement authentication without needing to understand the underlying library details.

Compatibility - Linux/Unix

---

## Index 
1. [Key Features](#key-features-of-auth-library-created-by-this-program)
2. [Pre Requisites](#pre-requisites)
3. [Libraries Used](#libraries-used)
4. [Data Base](#data-base)
5. [Setting Up Project](#setting-up-the-project)
6. [Using The Library You Created](#what-singhautha-provides-you)
7. [Setting Up Mongo DB](#setup-mongo-db)
8. [Final Remarks and Future Scope](#final-remarks-and-future-scope)

---

### Key Features of Auth Library Created by This Program:

- **User Registration:** Secure and intuitive process for creating new user accounts.
- **Login System:** Efficient login mechanism with secure password verification.
- **Password Management:** Password encryption using Encoding Algorithms.
- **Input Validation:** Prevents buffer overflows and other security vulnerabilities.
- **Scalable Design:** Easy integration into larger systems or applications.

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

###### Estimated Time Complexity for Brute Force Attack:

*Case 1 :- You changed the my lookups and Reverse Lookups Values Keeping the length same of everything*

The time complexity of a brute-force attack on this encoding function can be estimated as:

\[
3 * 95^n + 2^{32}
\] 
Written as
\[
O(95^n)
\]


where \(n\) is the password length.

For short passwords (4-6 characters):

The number of combinations ranges from billions to trillions.(1 Arab to 1 Kharab)
While still a large number, these could potentially be cracked with significant computing resources, though it would take considerable time.

For medium-length passwords (7-10 characters):

The combinations increase dramatically, reaching quintillions to septillions.
This level of complexity makes brute force attacks extremely challenging, requiring enormous computing power and time.

For long passwords (11 characters and above):

The number of combinations becomes astronomical, reaching decillions, undecillions, and beyond.
At this level, brute force attacks become practically impossible with current or foreseeable technology.

It's important to note that for each additional character in the password, the complexity increases by a factor of 95 (assuming all printable ASCII characters). This is then multiplied by the 4 billion possibilities from the 32-bit public key, resulting in an exponential increase in complexity for each added character.

This analysis demonstrates that passwords of 8 characters or more, when hashed with the Singla Algorithm, present an extremely formidable challenge to brute force attacks. The complexity levels quickly reach a point that is difficult to comprehend in human-relatable terms.

*Case 2 :-If you are using my Lookup and Reverse Lookup*

Btw I generated them using a Java Program to have it easy :)

So The Time Complexity will be reduced ( Because My Repo is Public so Attacker can Identify ) to :-

\[
95^n + 2^{32}
\]
Written as
\[
O(95^n)
\]

For short passwords (4-6 characters):

The number of combinations is now in the range of 10^33 to 10^35. (1 decillion to 100 decillion) (1 lakh crore crore to 100 lakh crore crore)
While significantly reduced from our previous estimate, this is still an enormous number.
It would take thousands to tens of thousands of years for a supercomputer checking a trillion combinations per second.

For medium-length passwords (7-10 characters):

The combinations increase to the range of 10^36 to 10^39 (1 undecillion to 1 duodecillion) (10 crore crore crore to 1000 crore crore crore) 
This would take millions to billions of years for our hypothetical supercomputer.

For long passwords (11 characters and above):

The number of combinations reaches 10^40 and beyond (10 duodecillion and beyond) (10 lakh crore crore crore and beyond)
Even with the known lookup tables, this level of complexity makes brute force attacks practically infeasible with current technology.

The complexity has indeed decreased compared to our previous analysis where all components were unknown. However, it remains extremely high due to several factors:

The password itself still contributes \(95^{n}\) combinations, where n is the password length.

In practical terms, this means that even with knowledge of the lookup tables:

Very short passwords (3-4 characters) might be crackable with significant resources, but it would still be a time-consuming process.
Passwords of 8 characters or more remain extremely secure against brute force attacks, with complexity levels that would require millions to billions of years to exhaust all possibilities, even with powerful computing resources.

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

### Final Remarks and Future Scope

- Compatibility With Windows
- GUI 
- More Secure Token Generation
- Integration with Windows SSO

I Hope this will help you to have authentication feature in your C Programs with as ease as possible

[Connect on Linked for Feedback](https://www.linkedin.com/in/harshitsingla1761/) 