typedef struct {
    char signature[10];
    uint32_t payload_size;
} CustomHeader;

int check_buffer_size(int fd, CustomHeader *header) {
    ssize_t read_bytes;
    struct stat file_stat;
    
    read_bytes = read(fd, header, sizeof(CustomHeader));
    if (read_bytes != sizeof(CustomHeader))
        return -1; // Failed to read header
    
    header->payload_size = ntohl(header->payload_size);
    
    if (fstat(fd, &file_stat) != 0)
        return -1; // Failed to get file stats
    
    // Possible integer overflow
    if ((int)(sizeof(CustomHeader) + header->payload_size) != file_stat.st_size)
        return -1; // Buffer size mismatch
    
    return 0; // Buffer size valid
}