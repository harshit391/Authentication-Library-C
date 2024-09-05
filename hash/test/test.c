#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

void enterAndHashPassword(char arr[]);

void decode(char arr1[], char arr2[]);

void encode(char arr1[], char arr2[]);

bool compare(char arr1[], char arr2[]);

int main()
{
	char give[100];

	enterAndHashPassword(give); // Hello

	assert(strcmp(give, "$singla391$18$;xi&l") == 0);

	printf("All Test Cases for Encoding Passed\n");

	char pass[100];

	printf("Enter Your Account Password:- ");

	scanf("%[^\n]%*c", pass); // Hello

	assert(compare(give, pass) == true);

	decode(give, pass);

	assert(strcmp(pass, "Hello") == 0);

	printf("All Test Cases for Decoding Passed\n");

	return 0;
}
