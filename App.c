#include "singlaheader.h"

void login();

void signup();

void resetPass();

int main(void)
{
    // Initialize the MongoDB driver once at startup
    mongoc_init();

    printf("Welcome to the Singla Authentication in C\n\n");

    printf("Select One of the Options from Below :- \n\n");

    printf("1. Login\n");
    printf("2. Signup\n");
    printf("3. Reset Password\n");
    printf("4. Exit\n");

    int val = 0;
    char input[32];

    while (val == 0)
    {
        printf("Enter Your Choice :- ");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        if (sscanf(input, "%d", &val) != 1)
        {
            printf("Invalid Choice\n");
            continue;
        }

        if (val == 1)
        {
            login();
        }
        else if (val == 2)
        {
            signup();
        }
        else if (val == 3)
        {
            resetPass();
        }
        else if (val == 4)
        {
            break;
        }
        else
        {
            printf("Invalid Choice\n");
            val = 0;
        }
    }

    // Clean up the MongoDB driver once at shutdown
    mongoc_cleanup();

    return 0;
}
