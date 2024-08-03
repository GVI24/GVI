#include <stdio.h>
#include <string.h>

void append_user_input(char *prefix, char *user_input) {
    char buffer[256];
    strcpy(buffer, prefix); // Prefix added to buffer
    strcat(buffer, user_input); // Vulnerable: strcat with no bounds checking
    printf("Combined string: %s\n", buffer);
}

int main() {
    char prefix[] = "Your input: ";
    char input[512];
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);
    append_user_input(prefix, input);
    return 0;
}