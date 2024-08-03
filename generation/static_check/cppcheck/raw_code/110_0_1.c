#define HEADER_SIZE 1024

int validate_file_size(int fd) {
    off_t file_size;
    char header[HEADER_SIZE];
    int header_info;
    
    if (read(fd, header, HEADER_SIZE) != HEADER_SIZE)
        return -1; // Failed to read header
    
    // Simulate extracting an integer value from the header
    header_info = *(int*)header;
    
    // Incorrectly cast file size to int
    file_size = lseek(fd, 0, SEEK_END);
    if (HEADER_SIZE + (int)header_info != file_size)
        return -1; // Incorrect file size
    
    return 0; // File size valid
}