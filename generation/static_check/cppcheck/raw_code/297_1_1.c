void processImageData(uint8_t *imageData, uint32_t imageSize) {
    char imageBuffer[1024];
    // Vulnerability: No bounds checking on imageSize
    for (uint32_t i = 0; i < imageSize; i++) {
        imageBuffer[i] = imageData[i]; // Potential buffer overflow
    }
    printf("Image processed\n");
}
