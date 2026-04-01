#define MAX_SIZE 1000000

bool compare(char arr1[], char arr2[]);

void login()
{
	printf("\nEnter Your User Email :- ");

	char mail[100];

	scanf("\n%99[^\n]%*c", mail);

	if (!userExists(mail))
	{
		perror("User Not Found\n");
		exit(1);
	}

	printf("Enter Your Password :- ");

	char password[100];
	
	scanf("%99[^\n]%*c", password);

	char dbPassword[100];

	getPassword(mail, dbPassword, 100);

	int tries = 5;
		
	while(tries > 0 && (!(compare(dbPassword, password))))
	{
		tries--;
		if (tries == 0)
		{
			printf("You Exceeded the no. of tries\n");
			exit(1);
		}
		printf("Login Failed because of Wrong Password Tries Left :- %d\n", tries);
		printf("Enter Your Password Again :- ");
		scanf("%99[^\n]%*c", password);
	}

	printf("Login Successful\n");
}
