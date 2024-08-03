#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerable_copy(char *input) {
    char buf[256];
    strcpy(buf, input); // Vulnerable: No bounds checking
    printf("Buffer content: %s\n", buf);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        vulnerable_copy(argv[1]);
    }
    return 0;
}