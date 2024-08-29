#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sc[] = {94, 99, 47, 103, 72, 121, 36, 123, 93, 98, 115, 41, 106, 111, 113, 75, 40, 60, 71, 124, 62, 107, 64, 45, 43, 96, 118, 95, 34, 112, 69, 74, 70, 67, 120, 68, 73, 117, 59, 33, 125, 42, 37, 108, 102, 92, 39, 105, 63, 110, 58, 38, 91, 35, 46, 104, 126, 116, 97, 100, 114, 61, 44, 65, 119, 66, 122, 101, 109};

int revsc[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 28, 53, 6, 42, 51, 46, 16, 11, 41, 24, 62, 23, 54, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 38, 17, 61, 20, 48, 22, 63, 65, 33, 35, 30, 32, 18, 4, 36, 31, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 45, 8, 0, 27, 25, 58, 9, 1, 59, 67, 44, 3, 55, 47, 12, 21, 43, 68, 49, 13, 29, 14, 60, 10, 57, 37, 26, 64, 34, 5, 66, 7, 19, 40, 56};

char secret[] = "sajneet";

int arr2[] = {19, 1, 10, 14, 5, 5, 20};

void decode(char digest[])
{
	int n = strlen(digest);

	printf("Decoding :- %s\n", digest);

	int keys = 11;

	int key = 0;

	while (digest[keys] != '$')
	{
		key = key * 10 + (digest[keys] - '0');
		keys++;
	}	

	int j = 0;

	char *decoded = (char *) malloc(n - keys - 1);

	printf("Decoded Key :- %d\n", key);

	for (int i = keys + 1; i < n; i++)
	{
		int idx = revsc[digest[i]];

		int add = idx + 65;

		int bit = ((key >> j)&1);

		int org = (add * 2) + bit;

		int val = org - secret[j % 7] - arr2[j % 7];

		decoded[j] = val;
		
		j++;
	}

	printf("Decoded Value :- %s\n", decoded);
}

void binary(int n)
{
	for (int i = 32; i >= 0; i--) 
	{
		printf("%d", (n >> i)&1);
	} 
}

int main()
{
	char arr3[1000];

	printf("Enter Your Password :- ");

	scanf("%[^\n]%*c", arr3);

	while (strlen(arr3) > 30)
	{
		printf("\n");
		printf("Please Enter Password of length less than equal to 30\n");
		scanf("%[^\n]%*c", arr3);
	}

	int n = strlen(arr3);

	char *  digest = (char *) malloc(n);

	int key = 0;

	int j = 0;

	// printf("%d\n", n);

	for (int i = 0; i < n; i++)
	{
		// printf("Hashing :- %c\n", arr3[i]);

		int sum = arr3[i] + secret[i % 7]  + arr2[i % 7];

		// printf("Sum :- %d\n", sum);

		int half = sum / 2;

		if (sum % 2 == 1)
			key |= (1 << j);

		// printf("Half :- %d\n", half);

		// printf("Key :- %c\n", sum % 2);

		int diff = (half - 65);

		// printf("Diff :- %d\n", diff);

		int asci = sc[diff];

		// printf("Hashed Character :- %c\n", asci);

		digest[j] = (char)(asci);

		j++;
		
		// printf("------------------\n");
	}

	char start[] = "$";

	char hash[] = "$singla391$";

	char padding[12];

	sprintf(padding, "%d", key);
	
	strcat(hash, padding);
	strcat(hash, start);
	strcat(hash, digest);

	/*

	printf("digest :- %s\n", digest);

	printf("key :- ");
	binary(key);
	printf("\n");

	*/

	printf("Hashed Value :- %s\n", hash);

	decode(hash);

	return 0;
}
