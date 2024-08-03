void overflow_prone_stream_copy(FILE *input, FILE *output, size_t size) {
    char buffer[256];
    while (size > 0) {
        size_t chunk = (size > sizeof(buffer)) ? sizeof(buffer) : size;
        fread(buffer, 1, chunk, input);
        // Potential buffer overflow if 'size' calculation is off
        fwrite(buffer, 1, chunk, output);
        size -= chunk;
    }
}

