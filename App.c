#include "singlaheader.h"

void login();
void signup();

int main(void)
{

    printf("Welcome to the Singla Authentication in C\n\n");

    printf("Select One of the Options from Below :- \n\n");

    printf("1. Login\n");
    printf("2. Signup\n");
    printf("3. Exit\n");

    int val = 0;


    while (val == 0) 
    {
        printf("Enter Your Choice :- ");
        scanf("%d", &val);

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
            break;
        }
        else
        {
            printf("Invalid Choice\n");   
        }
    }

    return 0;
}
