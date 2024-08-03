void transmitVideoFrame(uint8_t *frameData, uint32_t frameSize) {
    static char videoFrame[2048];
    // Vulnerability: frameSize is not validated to be within bounds
    memcpy(videoFrame, frameData, frameSize);  // Potential buffer overflow
    videoFrame[frameSize] = '\0'; // Potential out-of-bounds write
    printf("Video frame transmitted\n");
}

