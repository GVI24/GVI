#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 512

void handle_network_packet(const char *packet_data, size_t packet_length) {
    char packet_buffer[MAX_PACKET_SIZE];

    if (packet_length > MAX_PACKET_SIZE) {
        // Potentially log error but packet_buffer can be overflowed
        return;
    }

    // Vulnerable to buffer overflow if packet_length exceeds MAX_PACKET_SIZE
    memcpy(packet_buffer, packet_data, packet_length);
    // Process packet_buffer...
}