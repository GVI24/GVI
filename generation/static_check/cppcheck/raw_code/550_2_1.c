#define MAX_PACKET_SIZE 512
#define REASSEMBLY_BUFFER_SIZE 128
typedef unsigned char byte;

void reassemble_network_packet(byte* packet_data, int packet_size) {
    byte reassembly_buffer[REASSEMBLY_BUFFER_SIZE];
    if (packet_size > MAX_PACKET_SIZE) {
        // Insecurely handling packets larger than the expected maximum
        exit(1);
    }
    // Direct copy without checking the size against REASSEMBLY_BUFFER_SIZE
    memcpy(reassembly_buffer, packet_data, packet_size); // Potential stack overflow
    // Network packet reassembly logic... (omitted)
}

