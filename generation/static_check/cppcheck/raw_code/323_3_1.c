#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH 1024

static void archiveLogs(const char *logDir) {
    char zipCommand[MAX_PATH + 50];

    // Potential Command Injection if logDir is not properly sanitized
    snprintf(zipCommand, sizeof(zipCommand), "zip -r logs.zip %s", logDir);

    // Improper Error Handling
    int result = system(zipCommand);
    if (result != 0) {
        fprintf(stderr, "Error archiving logs: %s. Exiting.\n", strerror(errno));
        exit(1); // Exits without further handling or cleanup
    }
}