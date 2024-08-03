#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void insecure_logging(char *message) {
    char log_buffer[BUFFER_SIZE];
    sprintf(log_buffer, "DEBUG: %s\n", message); // Potential Buffer Overflow
    printf("%s", log_buffer);

    // Imagine more operations here
    // ...
}

int main(int argc, char **argv) {
    if (argc > 1) {
        insecure_logging(argv[1]);
    }
    return 0;
}