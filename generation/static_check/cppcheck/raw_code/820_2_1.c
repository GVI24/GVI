#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 512

void parse_message(int sockfd) {
    char msg_buffer[MAX_MESSAGE_SIZE];
    int bytes_read;

    // Vulnerable to buffer overflow, as bytes_read can be larger than the buffer size
    bytes_read = recv(sockfd, msg_buffer, 1024, 0); // Incorrect size parameter
    if (bytes_read <= 0) {
        perror("Receive error");
        exit(EXIT_FAILURE);
    }
    msg_buffer[bytes_read] = '\0'; // Potentially writing outside of the buffer
    printf("Message: %s\n", msg_buffer);
}