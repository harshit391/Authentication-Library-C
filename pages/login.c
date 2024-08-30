#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../hash/singlaHashing.h"
#include <stdbool.h>

#define MAX_SIZE 1000000

extern int errno;

void readData(char data[])
{
	int fd;

	fd = open("usernames.txt", O_RDONLY);

	if (fd < 0) {
		perror("file");
		exit(1);
		return;
	}

	ssize_t total_bytes = 0;
	ssize_t bytes_read = 0;

	char *content = NULL;

	char buffer[MAX_SIZE];

	while ((bytes_read =  read(fd, buffer, MAX_SIZE)) > 0) {
		
		char * curr = realloc(content, total_bytes + bytes_read + 1);

		if (curr == NULL) {
			perror("Memory allocation failed");
			free(content);
			close(fd);
			exit(1);
		}

		content = curr;

		memcpy(content + total_bytes, buffer, bytes_read);

		total_bytes += bytes_read;
	}

	if (bytes_read < 0) {
		perror("Error Reading Failed");
		free(content);
		close(fd);
		exit(1);
	}

	close(fd);

	if (content) {
		content[total_bytes] = '\0';
	}

	strcpy(data, content);

	free(content);
}

bool checkExists(char currName[])
{
	char data[MAX_SIZE];

	readData(data);

	int len = strlen(currName);

	int n = strlen(data);

	char name[100];

	name[0] = '\0';

	int j = 0;

	for (int i = 0; i < n; i++)
	{
		if (data[i] == ',')
		{
			name[j] = '\0';
			
			if (strcmp(currName, name) == 0)
			{
				return true;
			}
			strcpy(name, "");

			j = 0;
		}
		else
	       	{
			name[j++] = data[i];
		}
	}

	return false;
}

int main()
{
	int fd = open("usernames.txt", O_RDONLY);

	if (fd == -1)
	{
		printf("No Data for Users\n");

		exit(1);
	}

	printf("Enter Your User Name :- ");

	char name[100];

	scanf("%[^\n]%*c", name);

	if (!checkExists(name))
	{
		printf("User Not Found\n");
		exit(1);
	}

	char password[100];
		
	enterAndHashPassword(password);
}
