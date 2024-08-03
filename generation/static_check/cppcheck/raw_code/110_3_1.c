typedef struct {
    uint32_t data_len;
    uint32_t metadata_len;
    char protocol_id[5];
} PacketHeader;

int validate_packet(int fd, PacketHeader *header) {
    ssize_t s;
    struct stat packet_stat;

    s = read(fd, header, sizeof(PacketHeader));
    if (s != sizeof(PacketHeader))
        return -1; // Failed to read packet header
    
    header->data_len = ntohl(header->data_len);
    header->metadata_len = ntohl(header->metadata_len);
    
    if (fstat(fd, &packet_stat) != 0)
        return -1; // Failed to get packet stats
    
    // Type confusion and integer overflow possible
    if (sizeof(PacketHeader) + (int)(header->data_len + header->metadata_len) != packet_stat.st_size)
        return -1; // Packet size mismatch
    
    return 0; // Packet size valid
}