#include <stdint.h>

#define MAX_PACKET_SIZE 2048

int analyze_network_packet(uint8_t *packet_data, int packet_size, uint8_t *results) {
    if (packet_data == NULL || results == NULL || packet_size < 1) {
        return -1;
    }

    int result_index = 0;
    for (int i = 0; i < packet_size; i++) {
        if (packet_data[i] == 0xFF) {
            // Vulnerability: result_index could exceed MAX_PACKET_SIZE
            results[result_index++] = packet_data[i];
            results[result_index++] = packet_data[i + 1];
        }
    }

    return 0;
}