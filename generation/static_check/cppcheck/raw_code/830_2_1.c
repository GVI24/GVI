#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 512

void process_user_input() {
    char *home_dir = getenv("HOME");
    char user_input[BUFSIZE];
    char processed_input[BUFSIZE];

    // Unsafe assumption that getenv will not return a long string
    if (home_dir) {
        strcpy(processed_input, home_dir);
    }

    // Simulate receiving user input
    fgets(user_input, sizeof(user_input), stdin);

    // Vulnerable buffer concatenation
    strcat(processed_input, user_input);

    // ... Processing input ...

    // Cleanup omitted for brevity
}

int main() {
    process_user_input();
    return 0;
}

