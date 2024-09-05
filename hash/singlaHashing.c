#include "singlaHashing.h"

/* Main Decoder Function  */
void decode(char digest[], char decoded[])
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
}

bool compare(char digest[], char userPass[])
{
	char decoded[100]; // Storing Decoded Value

	decode(digest, decoded); // Decoding the Digest

	// Comparing the Decoded Value with User Password
	return strcmp(decoded, userPass) == 0;
}

void encode(char password[], char hash[])
{
	int n = strlen(password);

	int key = 0; // User Public Key

	int j = 0;

	char digest[100]; // Creating a Basic Encoded Digest

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

	int totalLen = n + strlen(padding) + strlen(owner) + 1;
	
	// Creating the Hased Password
	strcat(hash, owner);
	strcat(hash, padding);
	strcat(hash, start);
	strcat(hash, digest);

	hash[totalLen] = '\0';
}

/* Main Function to Enter Password and Create a Hash Of it  */
void enterAndHashPassword(char hash[])
{
	// srand(time(NULL));

	char input_pass[100]; // Main Input Password
	input_pass[0] = '\0';

	printf("Enter Your Password (Length less than or equal to 30):- ");

	scanf("%[^\n]%*c", input_pass);

	if (strlen(input_pass) == 0)
	{
		printf("Empty Value Not Allowed\n");
		return;
	}

	while (strlen(input_pass) > 30)
	{
		printf("\n");
		printf("Please Enter Password of length less than equal to 30\n");
		scanf("%[^\n]%*c", input_pass);
	}
	
	// struct timeval before, after;

	// gettimeofday(&before, NULL);

	// long long before_mil = before.tv_sec * 1000LL + before.tv_usec / 1000;
	
	hash[0] = '\0';

	encode(input_pass, hash);

	// printf("Encoded Value :- %s\n", hash); // Printing the Encrypted Hashed Password

	// gettimeofday(&after, NULL);

	// long long after_mil = after.tv_sec * 1000LL + after.tv_usec / 1000;

//	printf("Time Taken :- %llu ms\n", after_mil - before_mil);
}
