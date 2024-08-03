#define BUFFER_SIZE 512
#define DATA_OFFSET 4

void process_network_packet(char *packet, unsigned int packet_length) {
    unsigned int data_length;
    char buffer[BUFFER_SIZE];

    if (packet_length < DATA_OFFSET) {
        // Error: packet too short
        return;
    }

    // Vulnerability: data_length can be larger than the buffer.
    data_length = *(unsigned int *)(packet);
    
    // Copy data into buffer without checking the actual buffer size
    memcpy(buffer, packet + DATA_OFFSET, data_length);

    // Process buffer...
}