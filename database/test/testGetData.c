#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../utils/getData.h"

// Path to the root of the project
char rootPath[] = "/vagrant/Authentication-System-C/";

int main()
{
	char filedata[130];
	char currPath[] = "database/files/mongouri.txt";

	char filepath[130];
	filepath[0] = '\0';

	strcat(filepath, rootPath);
	strcat(filepath, currPath);

	printf("%s\n", filepath);

	getDataFromFile(filedata, filepath);

	printf("%s\n", filedata);
}
