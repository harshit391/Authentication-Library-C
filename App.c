#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pages/login.h"
#include "pages/signup.h"

int main()
{
    printf("Hello World\n");

    int val = login();

    int sign = signup();

    printf("Value of login is %d\n", val);

    printf("Value of signup is %d\n", sign);

    return 0;
}