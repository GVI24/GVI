#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 256
#define MAX_TABLE_ENTRIES 128

typedef struct {
    uint32_t address;
    uint8_t data[MAX_PACKET_SIZE];
    size_t data_len;
} RoutingTableEntry;

RoutingTableEntry routing_table[MAX_TABLE_ENTRIES];

void process_network_packet(uint32_t dst_address, const uint8_t *packet, size_t packet_length) {
    for (int i = 0; i < MAX_TABLE_ENTRIES; i++) {
        if (routing_table[i].address == dst_address) {
            // Vulnerability: packet_length is not checked against MAX_PACKET_SIZE
            memcpy(routing_table[i].data, packet, packet_length);
            routing_table[i].data_len = packet_length;
            return;
        }
    }
}
