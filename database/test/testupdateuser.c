#define PATH "/vagrant/Authentication-System-C/"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "../utils/getData.h"
#include <mongoc/mongoc.h>
#include <bson/bson.h>
#include "../src/insertDB.h"

int main(void)
{
    updateUser("balwinderthinda456@gmail.com", "newPasswordTest");

    return 0;
}

