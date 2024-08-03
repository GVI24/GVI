#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error_exit(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

void process_data(const char *data) {
    // Vulnerable function processing data without proper checks
    char cmd[128];
    sprintf(cmd, "echo '%s'", data); // Possible command injection
    system(cmd);
}

int main(int argc, char *argv[]) {
    char input[256];
    if (argc > 1) {
        fread(input, 1, sizeof(input), stdin);
        process_data(input);
    } else {
        error_exit("No arguments given.");
    }
    return 0;
}