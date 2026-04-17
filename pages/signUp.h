void enterAndHashPassword(char arr[]);

void checkInvalidEntry(char val[])
{

	if (strlen(val) == 0)
	{
		fprintf(stderr, "Empty Value\n");
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
		fprintf(stderr, "Empty Value\n");
		exit(1);
	}

	else if ( !valid( mail[0] ))
	{
		fprintf(stderr, "Email can't start with a special character\n");
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
		fprintf(stderr, "Invalid Email\n");
		exit(1);
	}

	if ( !valid(mail[i]))
	{
		fprintf(stderr, "Invalid character after @\n");
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
		fprintf(stderr, "Cannot find '.' in domain part of email\n");
		exit(1);
	}

	while (i < n)
	{
		if ( !valid (mail[i]) && mail[i] != '.')
		{
			fprintf(stderr, "Invalid Email\n");
			exit(1);
		}
		i++;
	}
}

void signup()
{
	char name[100];

	printf("\nEnter Your Name :- ");
	scanf("\n%99[^\n]%*c", name);

	checkInvalidEntry(name);

	printf("\n");

	char email[100];

	printf("Enter Your Email :- ");
	scanf("%99[^\n]%*c", email);

	checkEmail(email);

	if(userExists(email))
	{
		printf("User Already Exists\n");
		exit(1);
	}

	printf("\n");

	char password[100];

	enterAndHashPassword(password);

	char verf_code[100];

	generate_verf_code(verf_code, 7);

	int res = sendMail(email, verf_code);

	if (res != 0)
	{
		fprintf(stderr, "Error in Sending Mail\n");
		exit(1);
	}

	char userinputCode[100];
	int tries = 5;

	printf("\nEnter the Verification Code Sent to Your Email :- \n");

	while (tries > 0)
	{
		scanf("%99[^\n]%*c", userinputCode);

		if (strcmp(userinputCode, verf_code) == 0)
		{
			break;
		}

		tries--;

		if (tries == 0)
		{
			printf("You Exceeded the no. of tries.\n");
			exit(1);
		}

		printf("Verification Failed. Please Enter Correct Code. Tries Left :- %d\n", tries);
	}

	printf("Verification Successful\n");

	insertUser(name, password, email);
}
