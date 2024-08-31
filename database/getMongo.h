#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

void getMongoURI(char uri_string[])
{
    int fd = open("mongouri.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Error");
	exit(1);
    }

    read(fd, uri_string, 100);
}
