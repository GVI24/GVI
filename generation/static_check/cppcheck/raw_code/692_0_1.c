#define BUFFER_SIZE 256

typedef struct {
    char data[BUFFER_SIZE];
} packet;

void process_packet(packet *pkt) {
    char buffer[BUFFER_SIZE];
    int packet_size = *(int *)(pkt->data); // Cast the first bytes to int to get packet size
    if (packet_size > BUFFER_SIZE) {
        // Improper validation can lead to buffer overflow
        memcpy(buffer, pkt->data + sizeof(int), packet_size);
    }
    // ... further processing ...
}