#include <string.h>

void decompress_packet(char *compressed_data, int compressed_size, char *decompressed_data, int decompressed_size) {
    // Fake decompression logic for example purposes
    for (int i = 0; i < compressed_size; i += 2) {
        decompressed_data[i / 2] = compressed_data[i]; // Take every other byte
    }

    // Vulnerable: No check to ensure compressed_size/2 is less than decompressed_size
}