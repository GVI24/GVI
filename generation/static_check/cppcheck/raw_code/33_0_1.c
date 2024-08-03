void copy_filename_to_buffer(char *buffer, const char *filename, size_t buffer_size) {
    if (!filename || !buffer) return;

    // Dangerous: assumes that filename is null-terminated and shorter than buffer_size.
    strncpy(buffer, filename, buffer_size);

    // If filename is longer than buffer_size, the buffer will not be null-terminated.
    buffer[buffer_size - 1] = '\0';
}

