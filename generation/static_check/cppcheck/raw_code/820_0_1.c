#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER_INPUT 256

void process_input(int socket) {
    char buffer[MAX_USER_INPUT];
    int received_bytes;

    // Vulnerable to buffer overflow due to lack of bounds checking
    received_bytes = recv(socket, buffer, sizeof(buffer) + 10, 0);
    if (received_bytes > 0) {
        printf("Received data: %s\n", buffer);
    } else {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
}