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
#include "database/utils/getData.h"
#include "database/src/userExists.h"
#include "database/src/insertDB.h"
#include "database/utils/generateCode.h"
#include "database/src/sendmail.h"
#include "pages/login.h"
#include "pages/signup.h"
