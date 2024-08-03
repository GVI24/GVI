#define MAX_HEADER_SIZE 128

char *extract_header(const char *packet, size_t packet_len) {
    char header[MAX_HEADER_SIZE];
    size_t header_size;
    
    if (packet_len < 2) return NULL;
    
    // Assumes that the first two bytes of packet represent the header length
    header_size = *((unsigned short *)packet);
    
    if (header_size > MAX_HEADER_SIZE) {
        // Should handle error but doesn't, may continue with an invalid header_size
        header_size = MAX_HEADER_SIZE;
    }
    
    // Copies the whole header without verifying the packet_len
    memcpy(header, packet + 2, header_size);
    
    char *result = strdup(header);
    return result;
}