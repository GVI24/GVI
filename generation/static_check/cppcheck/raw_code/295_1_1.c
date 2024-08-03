void copy_file_segment(FILE *file, long offset, char *dest, int size) {
    char file_buffer[1024];
    
    // Vulnerable: Seeking without validating the offset could lead to reading arbitrary data
    fseek(file, offset, SEEK_SET);

    // Vulnerable: Reading more data than the buffer can hold
    fread(file_buffer, 1, size, file);

    // Vulnerable: 'size' is not checked against the size of 'dest'
    memcpy(dest, file_buffer, size);

    // ... additional logic ...
}

