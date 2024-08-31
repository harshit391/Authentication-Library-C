#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../hash/singlaHashing.h"
#include "../database/insertDB.h"
#include <errno.h>

void checkInvalidEntry(char val[])
{

	if (strlen(val) == 0)
	{
		perror("Empty Value");
		exit(1);
	}
}

int valid(char c)
{
	int lower = (c >= 'a' && c <= 'z');

	int upper = (c >= 'A' && c <= 'Z');

	return lower || upper;
}

void checkEmail(char mail[])
{

	if ( strlen( mail ) == 0 )
	{
		perror("Empty Value");
		exit(1);
	}

	else if ( !valid( mail[0] ))
	{
		perror("Email Can't start with Special Character");
		exit(1);
	}

	int n = strlen(mail);
	
	int i = 1;

	int afound = 0;

	while (i < n - 3)
	{
		if (mail[i] == '@')
		{
			afound = 1;
			i++;
			break;
		}
		i++;
	}

	if (!afound)
	{
		perror("Invalid Email");
		exit(1);
	}
	
	if ( !valid(mail[i]))
	{
		perror("Invalid Character After @");
		exit(1);
	} 
	else 
	{
		i++;
	}

	int dotfound = 0;

	while (i < n - 1)
	{
		if (mail[i] == '.')
		{
			dotfound = 1;
			i++;
			break;
		}
		i++;
	}

	if (!dotfound)
	{
		perror("Can't able to find . before the last character");
		exit(1);
	}

	while (i < n)
	{
		if ( !valid (mail[i]))
		{
			perror("Invalid Character After .");
			exit(1);
		}
		i++;
	}
}

int main()
{
	char name[100];

	printf("Enter Your Name :- ");
	scanf("%[^\n]%*c", name);

	checkInvalidEntry(name);

	printf("\n");

	char email[100];

	printf("Enter Your Email :- ");
	scanf("%[^\n]%*c", email);

	checkEmail(email);

	printf("\n");

	char password[100];

	enterAndHashPassword(password);

	insertDB(name, password, email);

	return 0;
}
