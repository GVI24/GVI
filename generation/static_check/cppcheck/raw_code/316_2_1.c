int copy_file_contents(const char *src, const char *dest, size_t block_size) {
    char *buffer;
    int src_fd = open(src, O_RDONLY);
    int dest_fd = open(dest, O_WRONLY | O_CREAT, 0666);
    if (src_fd < 0 || dest_fd < 0) return -1;
    off_t offset = 0;
    ssize_t read_bytes;
    while ((read_bytes = pread(src_fd, buffer, block_size, offset)) > 0) {
        size_t total_bytes = block_size * read_bytes; // Potential integer overflow
        if (pwrite(dest_fd, buffer, total_bytes, offset) != total_bytes) {
            // Handle partial write
            close(src_fd);
            close(dest_fd);
            return -1;
        }
        offset += total_bytes; // Potential integer overflow
    }
    close(src_fd);
    close(dest_fd);
    return 0;
}