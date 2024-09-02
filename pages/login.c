#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../database/getData.h"
#include "../hash/singlaHashing.h"
#include "../database/userExists.h"

#define MAX_SIZE 1000000

extern int errno;

int main()
{
	printf("Enter Your User Email :- ");

	char mail[100];

	scanf("%[^\n]%*c", mail);

	if (!userExists(mail))
	{
		perror("User Not Found\n");
		exit(1);
	}

	printf("Enter Your Password :- ");

	char password[100];
	
	scanf("%[^\n]%*c", password);

	char dbPassword[100];

	getPassword(mail, dbPassword, 100);
		
	while(!(decode(dbPassword, password)))
	{
		printf("Login Failed because of Wrong Password\n");
		printf("Enter Your Password Again :- ");
		scanf("%[^\n]%*c", password);
	}

	printf("Login Successful\n");

	return 0;
}
