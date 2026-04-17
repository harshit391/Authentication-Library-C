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
mkdir -p database/files

echo ""
echo ""

# Take input for full Path
echo "Enter the Full Path from Root Folder of Operating System :- "
echo "For Example :- /vagrant/Authentication-System-C/ (/ at the end is mandatory)"
read path
echo >> singlaheader.h
echo "#define PATH \"${path}\"" >> singlaheader.h

echo >> singlaheader.h
echo '#include "database/utils/getData.h"' >> singlaheader.h
echo '#include "database/src/userExists.h"' >> singlaheader.h
echo '#include "database/src/insertDB.h"' >> singlaheader.h
echo '#include "database/utils/generateCode.h"' >> singlaheader.h
echo '#include "database/src/sendmail.h"' >> singlaheader.h
echo '#include "pages/login.h"' >> singlaheader.h
echo '#include "pages/signUp.h"' >> singlaheader.h
echo '#include "pages/reset.h"' >> singlaheader.h

echo ""
echo ""

# Take input for email and saving it as text file in database folder
echo "Enter your email address : "
read email
printf '%s' "$email" > database/files/mailuser.txt
chmod 600 database/files/mailuser.txt

echo ""

# Take input for App Password for Gmail and saving it as text file in database folder
echo "Enter your App Password: "
read appword
printf '%s' "$appword" > database/files/mailpass.txt
chmod 600 database/files/mailpass.txt

echo ""

# Take input for MongoDb URL and saving it as text file in database folder
echo "Enter your MongoDb URL: "
read url
printf '%s' "$url" > database/files/mongouri.txt
chmod 600 database/files/mongouri.txt

echo ""

# Ending by printing the message
echo "Setup Completed Successfully"

echo ""

# End of the Script
echo "Please Run Command: ./app.sh to run the application"
echo "To Build the Static Library for whole Authentication System Run Command: ./Auth-Setup.sh"

echo "Thank You"
