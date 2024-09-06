#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>

int main(void)
{
    srand(time(NULL));

    int fd = open("tkn.txt", O_CREAT | 644);

    if (fd == -1)
    {
        perror("Error Creating");
        exit(1);
    }

    char genCode[100];
    genCode[0] = '\0';

    for (int i = 0; i < 100; i++)
    {
        genCode[i] = (char)(rand() % 65);
    }

    printf("%s\n", genCode);

    write(fd, genCode, 100);

    close(fd);

    return 0;
}