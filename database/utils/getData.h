

size_t getContentLength(char filePath[])
{

    int fd = open(filePath, O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file");
        exit(1);
    }

    char buffer[4096];

    ssize_t bytesRead;
    
    size_t totalLength = 0;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
    {
        for (ssize_t i = 0; i < bytesRead; i++)
        {
            if (buffer[i] != '\0')
            {
                totalLength++;
            }
            else
            {
                close(fd);
                return totalLength;
            }
        }
    }

    if (bytesRead == -1)
    {
        perror("Error reading file");
        close(fd);
        exit(1);
    }

    close(fd);

    return totalLength;
}

void getDataFromFile(char filedata[], char filePath[])
{
    char fullPath[1000];
    fullPath[0] = '\0';

    strcat(fullPath, PATH);
    strcat(fullPath, filePath);

    size_t contentLength = getContentLength(fullPath);
    
    int fd = open(fullPath, O_RDONLY);    

    if (fd == -1)
    {
        perror("Error opening file");
        exit(1);
    }

    ssize_t bytesRead = read(fd, filedata, contentLength);

    if (bytesRead == -1)
    {
        perror("Error reading file");
        close(fd);
        exit(1);
    }

    filedata[bytesRead] = '\0';

    close(fd);
}
