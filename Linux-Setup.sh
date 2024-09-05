# Setup GCC

# Updating The apt
sudo apt-get update

# Fixing the broken packages
sudo apt --fix-broken install

# Installing the build-essential and gcc
sudo apt install build-essential gcc --fix-missing

# Setting up The Required Libraries
sudo apt-get install libmongoc-dev
sudo apt-get install libcurl4-openssl-dev
sudo apt-get install pkg-config

# Setting up the files folders
mkdir database/files

echo ""
echo ""

# Take input for full Path
echo "Enter the Full Path from Root Folder of Operating System :- "
echo "For Example :- /vagrant/Authentication-System-C/ (/ at the end is mandatory)"
read path
echo >> singlaheader.h
echo "#define PATH \"$path"\ >> singlaheader.h

echo >> singlaheader.h
echo "#include \"database/utils/getData.h\"" >> singlaheader.h
echo "#include \"database/src/userExists.h\"" >> singlaheader.h
echo "#include \"database/src/insertDB.h\"" >> singlaheader.h
echo "#include \"database/utils/generateCode.h\"" >> singlaheader.h
echo "#include \"database/src/sendmail.h\"" >> singlaheader.h
echo "#include \"pages/login.h\"" >> singlaheader.h
echo "#include \"pages/signup.h\"" >> singlaheader.h

echo ""
echo ""

# Take input for email and saving it as text file in database folder
echo "Enter your email address without @gmail.com at the end: "
read email
echo $email > mailuser.txt
mv email.txt database/files

echo ""

# Take input for App Appword for Gmail and saving it as text file in database folder
echo "Enter your App Password: "
read appword
echo $appword > mailpass.txt
mv appword.txt database/files

echo ""

# Take input for MongoDb URL and saving it as text file in database folder
echo "Enter your MongoDb URL: "
read url
echo $url > mongouri.txt
mv mongouri.txt database/files

echo ""

# Ending by printing the message
echo "Setup Completed Successfully"

echo ""

# End of the Script
echo "Please Run Command: ./app.sh to run the application" 
echo "To Build the Static Library for whole Authentication System Run Command: ./Auth-Setup.sh"

echo "Thank You"