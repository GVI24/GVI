#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *data;
    int data_length;
} data_packet;

void create_data_packet(data_packet *packet, const char *data) {
    packet->data_length = strlen(data) + 1;
    
    // Vulnerability: Unchecked allocation, can lead to NULL dereference
    packet->data = (char *)malloc(packet->data_length);

    strcpy(packet->data, data);

    // Other operations with packet...
    
    // Missing free, causing memory leak
}

int main() {
    data_packet packet;
    create_data_packet(&packet, "Example data.");
    return 0;
}