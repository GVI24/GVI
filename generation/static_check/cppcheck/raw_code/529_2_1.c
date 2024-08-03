#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define BUFFER_SIZE 512

int receive_data(int socket_fd) {
    char data_buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(socket_fd, data_buffer, sizeof(data_buffer), 0);

    if (bytes_received > 0) {
        // Vulnerability: Assuming that bytes_received is less than BUFFER_SIZE
        data_buffer[bytes_received] = '\0'; // Possible off-by-one error

        // Process received data...
    }

    return bytes_received;
}