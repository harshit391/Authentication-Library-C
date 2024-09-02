#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>

int main() {
    const char *filename = "read_only_file.txt";
    const char *content = "Your content goes here.\n";

    // Step 1: Create a file and write content to it
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Write content to the file
    fprintf(file, "%s", content);
    fclose(file);

    // Step 2: Change the file's permissions to read-only
    if (chmod(filename, S_IRUSR | S_IRGRP | S_IROTH) != 0) {
        perror("Error setting file permissions");
        return EXIT_FAILURE;
    }

    // Step 3: Change ownership to another user (e.g., 'nobody')
    struct passwd *pw = getpwnam("nobody");
    if (pw == NULL) {
        perror("Error getting user information");
        return EXIT_FAILURE;
    }

    if (chown(filename, pw->pw_uid, pw->pw_gid) != 0) {
        perror("Error changing file ownership");
        return EXIT_FAILURE;
    }

    printf("File '%s' created with read-only permissions and ownership changed to 'nobody'.\n", filename);

    return EXIT_SUCCESS;
}
