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
		if ( !valid (mail[i]) && mail[i] != '.')
		{
			perror("Invalid Email\n");
			exit(1);
		}
		i++;
	}
}

void signup()
{
	char name[100];

	printf("\nEnter Your Name :- ");
	scanf("\n%[^\n]%*c", name);
	
//	printf("1\n");

	checkInvalidEntry(name);
	
//	printf("2\n");

	printf("\n");

	char email[100];

	printf("Enter Your Email :- ");
	scanf("%[^\n]%*c", email);

//	printf("3\n");
	checkEmail(email);

	if(userExists(email))
	{
		printf("User Already Exists\n");
		exit(1);
	}

//	printf("4\n");

	printf("\n");

	char password[100];
	
//	printf("5\n");

	enterAndHashPassword(password);
	
//	printf("6\n");

	char verf_code[100];
	
//	printf("7\n");

	generate_verf_code(verf_code, 7);

//	printf("8\n");

	int res = sendMail(email, verf_code);

//	printf("9\n");

	if (res != 0)
	{
		perror("Error in Sending Mail\n");
		exit(1);
	}

	char userinputCode[100];

	printf("\nEnter the Verification Code Sent to Your Email :- \n");

	scanf("%[^\n]%*c", userinputCode);

	int tries = 5;

	while (tries && strcmp(userinputCode, verf_code) != 0)
	{
		tries--;
		printf("Verfication Failed Please Enter Correct Code :- \n");
		scanf("%[^\n]%*c", userinputCode);
	}

	if (tries <= 0)
	{
		printf("You Exceeded the no. of tries.\n");
		exit(1);
	}
	
	printf("Verfication Successfull\n");

//	printf("10\n");
	insertDB(name, password, email);

//	printf("11\n");
}
