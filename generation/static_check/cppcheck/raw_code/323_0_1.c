#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void backupUserData(const char *username) {
    char backupCommand[256];

    // Potential Command Injection if username is not properly sanitized
    sprintf(backupCommand, "tar -czf /backup/%s.tar.gz /home/%s", username, username);

    // Improper Error Handling
    if (system(backupCommand) != 0) {
        fprintf(stderr, "Backup failed for user %s\n", username);
        exit(1); // Abruptly terminates without cleanup
    }
}