char *read_message(char *source, int length) {
    char *buffer;
    int message_length;
    
    if (length < 4) return NULL;
    
    // Reads message length without checking if length is greater than buffer size
    message_length = *(int *)source;
    
    // Allocates memory for the buffer without validating the message size
    buffer = (char *)malloc(message_length);
    if (!buffer) return NULL;
    
    // Reads the message without checking if it fits within the given length
    memcpy(buffer, source + 4, message_length);
    
    return buffer;
}