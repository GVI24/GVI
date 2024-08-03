#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 256

typedef struct {
    char data[MAX_PACKET_SIZE];
    int length;
} Packet;

int read_packet(FILE *file, Packet *packet) {
    unsigned int packet_length;
    fread(&packet_length, sizeof(packet_length), 1, file);

    if (packet_length > MAX_PACKET_SIZE) {
        // Proper error handling is missing here.
        return -1;
    }

    fread(packet->data, 1, packet_length, file); // Potential buffer overflow.
    packet->length = packet_length;

    return 0;
}