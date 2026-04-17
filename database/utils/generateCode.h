// Generate Verification Code using /dev/urandom for better randomness
void generate_verf_code(char *verfcode, int n)
{
    int fd = open("/dev/urandom", O_RDONLY);

    if (fd == -1)
    {
        // Fallback to time-based seed if /dev/urandom is unavailable
        srand(time(NULL));
        for (int i = 0; i < n - 1; i++)
        {
            verfcode[i] = '0' + (rand() % 10);
        }
        verfcode[n - 1] = '\0';
        return;
    }

    unsigned char buf[16];
    ssize_t bytes = read(fd, buf, sizeof(buf));
    close(fd);

    if (bytes < n - 1)
    {
        // Fallback if read failed
        srand(time(NULL));
        for (int i = 0; i < n - 1; i++)
        {
            verfcode[i] = '0' + (rand() % 10);
        }
        verfcode[n - 1] = '\0';
        return;
    }

    // Generate digits from random bytes
    for (int i = 0; i < n - 1; i++)
    {
        verfcode[i] = '0' + (buf[i] % 10);
    }

    // Terminate the code character array
    verfcode[n - 1] = '\0';
}
