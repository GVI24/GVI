#include <stdint.h>
#include <stdio.h>

#define MAX_PACKET_SIZE 1024

typedef struct {
    uint8_t *data;
    int size;
} DataPacket;

int process_packet(DataPacket *packet, uint8_t *processed_data, int max_size) {
    uint8_t *read_ptr = packet->data;
    int processed_size = 0;
    
    while (read_ptr < packet->data + packet->size) {
        // Assume the first byte indicates the amount of data to copy
        uint8_t data_size = *read_ptr++;
        // Vulnerability: No check to make sure data_size does not exceed packet->size
        if (processed_size + data_size > max_size) {
            // Not enough space in processed_data
            return -1;
        }
        // Vulnerability: No check for read_ptr being overrun
        memcpy(processed_data + processed_size, read_ptr, data_size);
        processed_size += data_size;
        read_ptr += data_size;
    }
    return processed_size;
}