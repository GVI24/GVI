typedef struct {
    unsigned char *packet_data;
    unsigned int max_packets;
    unsigned int packet_size;
} NetworkProcessor;

static void process_network_packets(NetworkProcessor *processor, const unsigned char *packets_stream, unsigned int stream_size) {
    unsigned int packet_count = 0;
    unsigned int offset = 0;
    while (offset < stream_size) {
        if (packet_count >= processor->max_packets) {
            // Vulnerability: No check before incrementing packet_count,
            // could overflow processor->packet_data if stream_size contains too many packets
            fprintf(stderr, "Packet buffer overflow error.\n");
            return;
        }
        memcpy(&(processor->packet_data[packet_count * processor->packet_size]), &packets_stream[offset], processor->packet_size);
        packet_count++;
        offset += processor->packet_size;
    }
}