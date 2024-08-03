#include <stdio.h>
#include <stdlib.h>

void echo_user_input() {
    char user_input[1024];
    int idx = 0;
    char input_char;

    printf("Enter input (will echo back): ");

    while ((input_char = getchar()) != '\n' && input_char != EOF) {
        if (idx < sizeof(user_input) - 1) {
            user_input[idx++] = input_char;
        }
    }
    user_input[idx] = '\0';

    printf("You entered: %s\n", user_input);
}