#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

char secret[] = "sajneet"; 

void createHash(char password[], int n, char digest[])
{
	int ip = 0, is = 0;

	for (int i = 0; i < n; i++)
	{
		digest[i] = (char)((password[i % n] & secret[i % 7])); 
	}

	digest[n] = '\0';
}

void enterPassword(char password[])
{
	int n = strlen(password);

	char digest[100];

	char start[] = "$singla$nn$";

	int k = (n * 7);

	start[8] = (char)(n/10 + '0');
	start[9] = (char)(n%10 + '0');

	printf("Start becomes :- %s\n", start);

	char newPass[100];
	
	for (int i = 0; i < n; i++)
	{
		createHash(password, n, digest);
		strcpy(password, digest);
		digest[100];
		printf("%s\n", password);
	}
}

int main()
{
	// Maximum Length can be 14
	char password[100];

	printf("Please Enter Password Length less then equal to 14 :- \n");

	scanf("%[^\n]%*c", password);

	while (strlen(password) > 14) 
	{
		printf("\nPlease Enter the Passowrd less then Equal to 14\n");

		scanf("%[^\n]%*c", password);
	}

	enterPassword(password);

	return 0;
}
