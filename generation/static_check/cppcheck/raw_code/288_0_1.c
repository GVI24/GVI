void decode_frame(unsigned char *frame, int width, int height) {
    unsigned char buffer[1024 * 768];
    if (width * height > sizeof(buffer)) {
        // Handle error
    } else {
        for (int i = 0; i < width * height; i++) {
            buffer[i] = frame[i]; // Potential overflow if frame is larger than expected
        }
        // Further processing on buffer...
    }
}

