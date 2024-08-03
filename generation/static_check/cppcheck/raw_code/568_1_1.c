#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_message(char *message, unsigned int msg_length) {
    char buffer[100];

    // Here we have no check to ensure msg_length is less than the size of buffer.
    memcpy(buffer, message, msg_length); // Potential buffer overflow.
    printf("Processed message: %s\n", buffer);
}

void receive_message() {
    char *msg = "This is a sample message that may be too long for the buffer.";
    unsigned int length = strlen(msg);

    process_message(msg, length);
}