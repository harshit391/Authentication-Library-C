#include "../singlaheader.h"

void login();
void enterAndHashPassword();
void signup();
void encode(char input[], char output[]);
void decode(char dbpassword[], char output[]);
bool compare(char dbpassword[], char userpassword[]);
void generate_verf_code(char output[], int n);
void getDataFromFile(char output[], char filePath[]);
void insertDB(char name[], char email[], char password[]);
int sendMail(char recipient[], char verficicationCode[]);
bool userExists(char email[]);
void getPassword(char email[], char output[], size_t passwordSize);

int main(void)
{
    printf("All Libraries are accessible It means\n\n");

    printf("Testing login()");
    login();
    printf("Login Working\n\n");

    printf("Testing SignUp()\n");
    signup();
    printf("Sign Up Working\n\n");


    printf("Testing enterAndHashPassword\n");
    char output[1000];

    enterAndHashPassword(output);

    printf("%s\n", output);

    printf("Enter and Hash Password is Working\n\n");

    printf("Testing encode()\n");

    encode("singlaJi", output);

    printf("%s\n", output);

    printf("Encode is Working\n\n");

    printf("Testing decode()");
    decode(output, output);

    printf("%s\n", output);
    printf("Decode is Working\n\n");

    printf("Testing compare() function\n");
    printf("%d\n", compare("singlaJi", output));
    printf("Compare is Working\n\n");

    printf("Testing generate_verf_code()\n");
    generate_verf_code(output, 7);
    printf("%s\n", output);
    printf("Generate Verfication Code is Working\n\n");

    printf("Testing getDataFromFile()\n");
    getDataFromFile(output, "database/files/mongouri.txt");
    printf("Get Data From File is Working\n");

    printf("Testing insertDB()\n");
    insertDB("Harshit Singla", "test@gmail.com", "helloworld");
    printf("insertDB is Working\n\n");

    printf("Testing sendMail()\n");
    sendMail("harshit391.be22@chitkara.edu.in", output);
    printf("sendMail is Working\n\n");

    printf("Testing userExists()\n");
    printf("%d\n", userExists("test@gmail.com"));
    printf("test@gmail.com\n\n");

    printf("Testubg getPassword()\n");
    getPassword("test@gmail.com", output, 100);
    printf("%s\n", output);
    printf("Get Password is Working\n\n");

    return 0;
}