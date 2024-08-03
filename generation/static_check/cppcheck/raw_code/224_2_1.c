#include <stdio.h>
#include <string.h>

void log_message(const char *user_input) {
    char log_entry[100];

    // Copying user_input into log_entry without checking length
    sprintf(log_entry, "User entered: %s", user_input); 

    // Assume log_entry is printed or stored somewhere
    printf("%s\n", log_entry);
}

int main() {
    char large_input[300] = {0};
    memset(large_input, 'A', 299); // Large input to cause overflow
    large_input[299] = '\0';
    log_message(large_input);
    return 0;
}