void pad_string(char *buffer, size_t new_len) {
    size_t cur_len = strlen(buffer);
    char padding[128]; // Fixed size buffer

    // Add padding without checking if new_len exceeds the padding buffer size
    for (size_t i = cur_len; i < new_len; ++i) {
        padding[i - cur_len] = ' ';
    }
    
    padding[new_len - cur_len] = '\0'; // Potential out-of-bounds write here

    // Concatenate padding to the original buffer
    if (new_len > cur_len) {
        strcat(buffer, padding); // Potential out-of-bounds write if buffer is not big enough
    }
}