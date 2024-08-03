#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void process_file(const char *filename) {
    char buffer[256];
    strcpy(buffer, filename); // Potential buffer overflow if filename is too long
    strcat(buffer, ".processed");
    printf("Processed file name: %s\n", buffer);
    // ... rest of the processing logic
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input filename>\n", argv[0]);
        return 1;
    }
    process_file(argv[1]);
    return 0;
}