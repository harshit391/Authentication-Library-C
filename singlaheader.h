// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Unix Libraries
#include <errno.h>
#include <limits.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>

// MongoDB Libraries
#include <mongoc/mongoc.h>
#include <bson/bson.h>

// cURL Library for sending emails
#include <curl/curl.h>

// Custom Headers
#include "hash/singlaHashing.h"
#include "database/getData.h"
#include "database/userExists.h"
#include "database/insertDB.h"
#include "database/generateCode.h"
#include "database/sendmail.h"
#include "pages/login.h"
#include "pages/signup.h"
