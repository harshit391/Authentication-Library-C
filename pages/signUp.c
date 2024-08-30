#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../hash/singlaHashing.h"
#include "../database/insertDB.h"

int main()
{
	char name[100];

	printf("Enter Your Name :- ");
	scanf("%[^\n]%*c", name);

	printf("\n");

	char email[100];

	printf("Enter Your Email :- ");
	scanf("%[^\n]%*c", email);

	printf("\n");

	char password[100];

	enterAndHashPassword(password);

	insertDB(name, password, email);

	return 0;
}
