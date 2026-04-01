#!/bin/bash
set -e

# Write config files from environment variables
if [ -z "$MONGO_URI" ] || [ -z "$MAIL_USER" ] || [ -z "$MAIL_PASS" ]; then
    echo "Error: MONGO_URI, MAIL_USER, and MAIL_PASS environment variables are required."
    echo ""
    echo "Usage:"
    echo "  docker run -it \\"
    echo "    -e MONGO_URI='mongodb+srv://user:pass@cluster.mongodb.net' \\"
    echo "    -e MAIL_USER='you@gmail.com' \\"
    echo "    -e MAIL_PASS='your-app-password' \\"
    echo "    singla-auth"
    exit 1
fi

printf '%s' "$MONGO_URI" > /app/database/files/mongouri.txt
printf '%s' "$MAIL_USER" > /app/database/files/mailuser.txt
printf '%s' "$MAIL_PASS" > /app/database/files/mailpass.txt

exec /app/singla-auth
