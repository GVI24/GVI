void init_video_frame(char *frameBuffer, int bufferSize) {
    char defaultFrame[256];
    memset(defaultFrame, 0, sizeof(defaultFrame));
    
    // Vulnerability: copying more bytes than the destination can handle
    // thus causing a buffer overflow if bufferSize is > 256.
    memcpy(frameBuffer, defaultFrame, bufferSize);
}

// Usage Example:
// char frame[128];
// init_video_frame(frame, 512); // Causes a buffer overflow