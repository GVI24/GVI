#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
} Packet;

void receive_packet(Packet *pkt, const char *incoming_data) {
    if (incoming_data) {
        // Unsafe copy without bounds checking
        strcpy(pkt->data, incoming_data); 
    }
}

int main() {
    Packet *new_packet = malloc(sizeof(Packet));
    const char *data = "This data is too long and will overflow the Packet data buffer causing potential code execution.";
    receive_packet(new_packet, data);
    free(new_packet);
    return 0;
}