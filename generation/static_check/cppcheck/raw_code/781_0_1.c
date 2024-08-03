int read_image_data(FILE *file, int offset, int size, unsigned char *buffer) {
    int read_size;
    if (fseek(file, offset, SEEK_SET) != 0) {
        return -1;
    }
    
    read_size = fread(buffer, 1, size, file);
    
    if (read_size != size) {
        return -1;
    }
    
    // Vulnerable: buffer overflow if 'buffer' is smaller than 'size'
    process_image_data(buffer, size);
    
    return 0;
}

