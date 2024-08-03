#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>

bool receive_data(int sock) {
    unsigned int data_size;
    recv(sock, &data_size, sizeof(data_size), 0);

    // Vulnerability: data_size may be too large
    char *buffer = (char *)malloc(data_size);
    if(buffer == NULL) {
        // Memory allocation failed
        return false;
    }
    
    ssize_t bytes_received = recv(sock, buffer, data_size, 0);
    if (bytes_received <= 0) {
        // Failed to receive data
        free(buffer);
        return false;
    }

    // Process buffer...
    // ...

    free(buffer);
    return true;
}