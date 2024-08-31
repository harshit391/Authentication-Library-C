#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../hash/singlaHashing.h"
#include <stdbool.h>

#define MAX_SIZE 1000000

extern int errno;

int main()
{
	printf("Enter Your User Email :- ");

	char mail[100];

	scanf("%[^\n]%*c", mail);

	if ( !checkExists( mail ) )
	{
		perror("User Not Found\n");
		exit(1);
	}

	char password[100];
		
	enterAndHashPassword(password);
}
