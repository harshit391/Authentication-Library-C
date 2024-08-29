#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int sc[] =  {33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125, 126, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75}; */

int sc[] = {104, 107, 110, 111, 106, 93, 64, 109, 122, 98, 115, 99, 70, 45, 71, 74, 68, 92, 114, 73, 124, 117, 34, 43, 37, 103, 62, 36, 97, 108, 42, 95, 58, 69, 65, 66, 38, 101, 75, 35, 91, 105, 120, 72, 100, 113, 67, 123, 125, 102, 44, 112, 126, 118, 41, 46, 116, 94, 121, 63, 96, 40, 59, 119, 47, 33, 61, 60, 39};

void decode(char digest[])
{
	int n = strlen(digest);

	for (int i = 0; i < n; i++)
	{
			
	}
}

int main()
{
	char arr3[1000];

	char secret[] = "sajneet";

	 scanf("%[^\n]%*c", arr3);

	char digest[100];

	int j = 0;

	int n = strlen(arr3);

	printf("%d\n", n);

	int arr2[] = {19, 1, 10, 14, 5, 5, 20};

	for (int i = 0; i < n; i++)
	{
		printf("Hashing :- %c\n", arr3[i]);

		int sum = arr3[i] + secret[i % 7]  + arr2[i % 7];

		printf("Sum :- %d\n", sum);

		int half = sum / 2;

		printf("Half :- %d\n", half);

		int diff = (half - 97) + 32;

		printf("Diff :- %d\n", diff);

		int asci = sc[diff];

		printf("Hashed Character :- %c\n", asci);

		digest[j++] = (char)(asci);
		
		printf("------------------\n");
	}
	
	digest[j] = '\0';

	printf("Hashed Value :- %s\n", digest);

	return 0;
}
