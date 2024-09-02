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

# Take input for email and saving it as text file in database folder
echo "Enter your email address: "
read email
echo $email > email.txt

# Take input for App Appword for Gmail and saving it as text file in database folder
echo "Enter your App Password: "
read appword
echo $appword > appword.txt

# Take input for MongoDb URL and saving it as text file in database folder
echo "Enter your MongoDb URL: "
read url
echo $url > mongouri.txt

# Ending by printing the message
echo "Setup Completed Successfully"

# End of the Script
echo "Please Run Command: ./app.sh to run the application" 