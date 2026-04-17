

void getDataFromFile(char filedata[], char filePath[], size_t filedata_size)
{
    char fullPath[1000];
    snprintf(fullPath, sizeof(fullPath), "%s%s", PATH, filePath);

    // Use stat() to get file size instead of reading the file twice
    struct stat st;
    if (stat(fullPath, &st) == -1)
    {
        perror("Error getting file info");
        exit(1);
    }

    size_t contentLength = (size_t)st.st_size;

    // Clamp to output buffer size to prevent overflow
    if (contentLength >= filedata_size)
    {
        contentLength = filedata_size - 1;
    }

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

    // Strip trailing newline/whitespace that config files may have
    while (bytesRead > 0 && (filedata[bytesRead - 1] == '\n' ||
           filedata[bytesRead - 1] == '\r' || filedata[bytesRead - 1] == ' '))
    {
        bytesRead--;
        filedata[bytesRead] = '\0';
    }

    close(fd);
}
