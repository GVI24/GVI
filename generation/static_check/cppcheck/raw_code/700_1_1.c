#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_message(char *message) {
    char buffer[50];
    int message_length = strlen(message);
    
    // Vulnerable to buffer overflow due to lack of bounds checking
    if (message_length > 50) {
        printf("Message is too long!\n");
        exit(1);
    }
    
    strcpy(buffer, message);
    
    printf("Message: %s\n", buffer);
}
