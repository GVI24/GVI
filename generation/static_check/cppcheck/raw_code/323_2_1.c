#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

static void logSystemStats(const char *filename) {
    FILE *logFile;
    char *sysCommand = "vmstat -s";

    logFile = fopen(filename, "a");
    if (!logFile) {
        perror("Could not open log file");
        exit(1); // Abrupt exit, no cleanup
    }

    if (system(sysCommand) != 0) {
        fprintf(stderr, "Failed to get system stats\n");
        // Potential resource leak - logFile is not closed
    }

    // File should be closed here, but it's missing
    // fclose(logFile); // Correct action that should be taken
}