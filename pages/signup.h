int signup()
{
    char name[100];

    char email[100];

    char pass[100];

    printf("Enter your Name :- ");

    scanf("%[^\n]%*c", name);

    printf("Enter your Email :- ");

    scanf("%[^\n]%*c", email);

    printf("Enter your Password :- ");

    scanf("\n%[^\n]%*c", pass);

    printf("%s - %s - %s\n", name, email, pass);

    return 0;
}