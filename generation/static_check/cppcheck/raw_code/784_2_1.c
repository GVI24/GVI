void text_decode(char *source, int sourceSize, char *destination, int destSize) {
    if (!source || !destination) return;
    
    int srcIndex = 0, destIndex = 0;
    while (srcIndex < sourceSize) {
        if (destIndex >= destSize) {
            // Buffer overflow: No room in destination buffer
            break;
        }
        // Assume some decoding process takes place here
        destination[destIndex++] = source[srcIndex++];
    }
    
    // Use-after-free: Source buffer is freed elsewhere, but pointers may still be used
}

