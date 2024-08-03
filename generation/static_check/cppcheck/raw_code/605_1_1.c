#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *address;
    short port;
} media_channel;

void initialize_media_channel(media_channel *channel, const char *address, short port) {
    // Vulnerability: Memory is allocated but not correctly managed
    channel->address = (char *)malloc(50 * sizeof(char));
    
    if (!channel->address) {
        return;
    }
    
    strcpy(channel->address, address);
    channel->port = port;

    // Assume operations with the channel happen here

    if (port % 2 == 0) {
        // Conditional free, can lead to memory leaks
        free(channel->address);
    }
}

int main() {
    media_channel channel;
    initialize_media_channel(&channel, "192.168.1.100", 8080);
    return 0;
}