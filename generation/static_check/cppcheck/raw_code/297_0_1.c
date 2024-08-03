void sendAudioData(uint8_t *audioStream, uint32_t streamLength) {
    char audioBuffer[BUFFER_SIZE];
    // Vulnerability: No check on streamLength against BUFFER_SIZE
    memcpy(audioBuffer, audioStream, streamLength); 
    printf("Sending audio data: %s\n", audioBuffer);
}
