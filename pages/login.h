#include "sha256i.h"

int login()
{
    char name[100];

    char pass[100];

    printf("Enter your Email :- ");

    scanf("%[^\n]%*c", name);

    printf("Enter your Password :- ");

    scanf("\n%[^\n]%*c", pass);

    hashthepass(pass);

    printf("%s - %s\n", name, pass);

    return 0;
}