/*
 * This File contains the Implementation for Singla Hashing Algorithm :)
 */

/* Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lookup  */
int sc[] = {94, 99, 47, 103, 72, 121, 36, 123, 93, 98, 115, 41, 106, 111, 113, 75, 40, 60, 71, 124, 62, 107, 64, 45, 43, 96, 118, 95, 34, 112, 69, 74, 70, 67, 120, 68, 73, 117, 59, 33, 125, 42, 37, 108, 102, 92, 39, 105, 63, 110, 58, 38, 91, 35, 46, 104, 126, 116, 97, 100, 114, 61, 44, 65, 119, 66, 122, 101, 109};

/* Reverse Lookup */
int revsc[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 28, 53, 6, 42, 51, 46, 16, 11, 41, 24, 62, 23, 54, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 38, 17, 61, 20, 48, 22, 63, 65, 33, 35, 30, 32, 18, 4, 36, 31, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 45, 8, 0, 27, 25, 58, 9, 1, 59, 67, 44, 3, 55, 47, 12, 21, 43, 68, 49, 13, 29, 14, 60, 10, 57, 37, 26, 64, 34, 5, 66, 7, 19, 40, 56};

/* Secret Key */
char secret[] = "sajneet";

/* 2nd Secret Key  */
int arr2[] = {19, 1, 10, 14, 5, 5, 20};

/* Main Decoder Function  */
void decode(char digest[])
{
	int n = strlen(digest); // Calculate the length of digest

	int keys = 11; // Skipping the $singla391$ part

	// Calculating the password key
	int key = 0;

	while (digest[keys] != '$')
	{
		key = key * 10 + (digest[keys] - '0');
		keys++;
	}	

	int j = 0; // Let's start Decoding

	char decoded[1000]; // Storing Decoding Value here

	for (int i = keys + 1; i < n; i++)
	{
		int reverse_lookup = revsc[digest[i]] + 65; // Reverse Lookup

		int curr_bit = ((key >> j)&1); // Current Bit

		int org_val = (reverse_lookup * 2) + curr_bit; // Original Value 

		int val = org_val - secret[j % 7] - arr2[j % 7]; // Decoded Character
 
		decoded[j] = val; // Storing the current Decoded Character
		
		j++;
	}

	decoded[j] = '\0';
	
	printf("Decoded Value :- %s\n", decoded); // And Here we got the decoded value
}

void encode(char password[], char hash[])
{
	int n = strlen(password);
	
	int key = 0; // User Public Key

	int j = 0;

	char digest[1000]; // Creating a Basic Encoded Digest

	/* Entire Singla Hashing Algo */
	for (int i = 0; i < n; i++)
	{
		int sum = password[i] + secret[i % 7]  + arr2[i % 7]; // Summing up the values of password , secret 1 , secret 2

		int half = sum / 2; // Taking Half of the value

		if (sum % 2 == 1)
		{
			key |= (1 << j); // Calculating the User key where we have to add 1 while decoding
		}

		int diff = (half - 65); // Subtracting Value of 'A' to fit in the curr Lookup Array

		int asci = sc[diff]; // Extracing Encoded Character from Lookup 'sc'

		digest[j] = (char)(asci); // Storing Encoded Value in Digest

		j++;	
	}

	digest[j] = '\0';

	// Some Extra Strings to Add in Encoded value for fun
	char start[] = "$"; 

	char owner[] = "$singla391$";

	char padding[12];

	// Converting key to string
	sprintf(padding, "%d", key);
	
	// Creating the Hased Password
	strcat(hash, owner);
	strcat(hash, padding);
	strcat(hash, start);
	strcat(hash, digest);
}

/* Main Function to Enter Password and Create a Hash Of it  */
void enterAndHashPassword()
{
	
	char input_pass[1000]; // Main Input Password

	printf("Enter Your Password :- ");

	scanf("%[^\n]%*c", input_pass);

	while (strlen(input_pass) > 30)
	{
		printf("\n");
		printf("Please Enter Password of length less than equal to 30\n");
		scanf("%[^\n]%*c", input_pass);
	}
		
	char hash[1000]; // Main Output Hashed Value

	encode(hash, hash);

	printf("Encoded Value :- %s\n", hash); // Printing the Encrypted Hashed Password
}

