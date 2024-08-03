#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fail(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int main(int argc, char **argv) {
    char buffer[1024];
    if (argc == 2 && strcmp(argv[1], "--print") == 0) {
        fread(buffer, 1, sizeof(buffer), stdin);
        if (!feof(stdin)) fail("Input too large or read error.");
        printf("%s", buffer); // Potential buffer overflow
    } else {
        fail("Usage: program --print");
    }
    return 0;
}