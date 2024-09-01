#include <stdio.h>
#include <stdlib.h>
#include "getMongo.h"

int main()
{
	char filedata[130];
	char filepath[] = "./mongouri.txt";

	getDataFromFile(filedata, filepath);

	printf("%s\n", filedata);

}
