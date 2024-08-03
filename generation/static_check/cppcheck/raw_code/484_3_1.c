typedef struct {
    unsigned char *data;
    size_t length;
} network_packet;

size_t store_packet_sequence(network_packet **packets, size_t packet_count) {
    size_t i = 0;
    network_packet *array = NULL;
    unsigned char buffer[1024];
    size_t read_size;

    while ((read_size = read_next_packet(buffer, &packet_count))) {
        SAFE_REALLOC(array, (i + 1) * sizeof(network_packet));
        array[i].data = (unsigned char *)malloc(read_size);
        memcpy(array[i].data, buffer, read_size);
        array[i].length = read_size;
        i++;
    }

    SAFE_REALLOC(array, (i + 1) * sizeof(network_packet));
    array[i].data = NULL;
    array[i].length = 0;

    *packets = array;
    return i;
}