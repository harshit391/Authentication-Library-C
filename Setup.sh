# Checking the MongoDB URI file alreaedy exists or not

if [ -f "database/mongouri.txt" ]; then
  echo "The file 'mongouri' already exists."
else
  touch "database/mongouri.txt"
  echo "The file 'uri' has been created."
fi
