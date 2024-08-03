int resize_buffer(char **buffer, int current_size, int new_size) {
    if (new_size <= current_size) {
        return current_size; // No resizing needed
    }

    char *temp = realloc(*buffer, new_size);
    if (temp == NULL) {
        perror("Failed to resize buffer");
        return -1; // Memory allocation error
    }

    *buffer = temp; // Memory is reallocated but not properly cleared

    // Omitted zeroing out the new memory, can lead to information disclosure
    return new_size;
}