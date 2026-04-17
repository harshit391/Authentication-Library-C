void enterAndHashPassword(char newPass[]);

void resetPass()
{
    char email[100];

    printf("\nPlease Enter the email :- ");
    scanf("\n%99[^\n]%*c", email);

    if (!userExists(email))
    {
        fprintf(stderr, "User Not Found\n");
        exit(1);
    }

    printf("Sending Verification Code ...\n");

    char code[8];

    generate_verf_code(code, 7);

    int res = sendMail(email, code);

    if (res != 0)
    {
        fprintf(stderr, "Error in Sending Mail\n");
        exit(1);
    }

    char userCode[8];
    int tries = 5;

    printf("You Have Received an Email for Verification Code. Please Enter :- ");

    while (tries > 0)
    {
        scanf("%7[^\n]%*c", userCode);

        if (strcmp(userCode, code) == 0)
        {
            break;
        }

        tries--;

        if (tries == 0)
        {
            printf("You Exceeded the No. of Tries. Please Try Again After some time\n");
            exit(1);
        }

        printf("Wrong Code. Tries Left :- %d\n", tries);
    }

    printf("Please Enter the New Password\n");

    char newPass[100];

    enterAndHashPassword(newPass);

    updateUser(email, newPass);

    printf("Password Reset Successful, You can Login Again :)\n");
}
