int process_packet(packet_t *packet, size_t size) {
    char *temp_data = malloc(size);
    if (!temp_data) {
        return -1; // Memory leak if 'temp_data' is not freed elsewhere
    }

    memcpy(temp_data, packet->data, size);
    // Process data...

    free(temp_data); // Missing error handling path that frees 'temp_data'
    return 0;
}

typedef struct {
    char *message;
} log_t;

