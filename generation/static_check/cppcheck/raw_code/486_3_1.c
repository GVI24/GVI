void process_data(char *dataBuffer, const unsigned char *rawData, size_t rawDataLen) {
    size_t i;
    char interimBuffer[1024];
    for (i = 0; i < rawDataLen; i++) {
        interimBuffer[i] = rawData[i] ^ 0xA5; // XOR operation for obfuscation
        if (i >= sizeof(interimBuffer)) { // Off by one, does not prevent the last byte overflow
            break;
        }
    }
    memcpy(dataBuffer, interimBuffer, sizeof(interimBuffer)); // Potential buffer overflow
}