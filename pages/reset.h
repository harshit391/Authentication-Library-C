void enterAndHashPassword(char newPass[]);

void resetPass()
{
    char email[100];

    printf("\nPlease Enter the email :- ");
    scanf("\n%[^\n]%*c", email);

    if (!userExists(email))
    {
        perror("User Not Found");
        exit(1);
    }

    printf("Sending Verification Code ...\n");

    char code[8];
    code[0] = '\0';

    generate_verf_code(code, 7);

    sendMail(email, code);

    char userCode[8];
    userCode[0] = '\0';

    int tries = 5;

    printf("You Have Recieved an Email for Verification Code Please Enter :- ");
    scanf("%[^\n]%*c", userCode);

    while (tries > 0 && strcmp(userCode, code) != 0)
    {
        printf("Wrong Code, Tries Left %d\n", tries);
        tries--;
        scanf("%[^\n]%*c", userCode);
    }

    if (tries <= 0)
    {
        printf("You Exceeded the No. of Tries Please Try Again After some time\n");
        exit(1);
    }

    printf("Please Enter the New Password\n");

    char newPass[100];

    enterAndHashPassword(newPass);

    updateUser(email, newPass);

    printf("Password Reset SuccessFull, You can Login Again :)\n");
}