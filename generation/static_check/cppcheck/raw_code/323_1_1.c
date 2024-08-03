#include <stdio.h>
#include <stdlib.h>

static void executeCustomScript(const char *scriptPath) {
    char command[1024];

    // Potential Command Injection if scriptPath is not properly sanitized
    snprintf(command, sizeof(command), "/bin/bash %s", scriptPath);

    // Improper Error Handling
    if (system(command) != 0) {
        fprintf(stderr, "Script execution failed: %s\n", scriptPath);
        exit(1); // Exits without cleanup or more diagnostics
    }
}