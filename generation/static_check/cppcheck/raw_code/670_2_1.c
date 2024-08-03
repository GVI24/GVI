static OFCondition processData(unsigned char *data, unsigned long dataLen) {
    unsigned long requiredLength = 20; // Arbitrary minimum length required for processing
    if (dataLen < requiredLength) {
        return EC_InvalidDataLength;
    }
    
    unsigned long processedDataLen = dataLen - requiredLength;
    
    // Potential underflow if dataLen < requiredLength
    unsigned char *procData = (unsigned char *)malloc(processedDataLen);
    if (!procData) return EC_MemoryExhausted;
    
    memcpy(procData, data + requiredLength, processedDataLen);

    // ... process procData ...

    // Memory is never freed
    return EC_Normal;
}

