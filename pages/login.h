#define DB_PASSWORD_MAX 4096

bool compare(char arr1[], char arr2[]);

void login()
{
	printf("\nEnter Your User Email :- ");

	char mail[100];

	scanf("\n%99[^\n]%*c", mail);

	if (!userExists(mail))
	{
		fprintf(stderr, "User Not Found\n");
		exit(1);
	}

	char dbPassword[DB_PASSWORD_MAX];

	if (!getPassword(mail, dbPassword, DB_PASSWORD_MAX))
	{
		fprintf(stderr, "Failed to retrieve password from database\n");
		exit(1);
	}

	printf("Enter Your Password :- ");

	char password[100];

	scanf("%99[^\n]%*c", password);

	int tries = 5;

	while (tries > 0)
	{
		if (compare(dbPassword, password))
		{
			printf("Login Successful\n");
			return;
		}

		tries--;

		if (tries == 0)
		{
			printf("You Exceeded the no. of tries\n");
			exit(1);
		}

		printf("Login Failed because of Wrong Password. Tries Left :- %d\n", tries);
		printf("Enter Your Password Again :- ");
		scanf("%99[^\n]%*c", password);
	}
}
