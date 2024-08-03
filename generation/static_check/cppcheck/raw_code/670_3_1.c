static OFCondition extractInformation(unsigned char *infoBuffer, unsigned long bufferSize) {
    unsigned long minSize = 16;
    if (bufferSize < minSize) return EC_InvalidBufferSize;
    
    unsigned char *bufPtr = infoBuffer;
    unsigned long infoLength;
    EXTRACT_LONG_BIG(bufPtr, infoLength);
    bufPtr += 4;
    
    if (infoLength > bufferSize - 4) return EC_InvalidInfoLength;
    
    char *infoStr = (char *)malloc(infoLength);
    if (!infoStr) return EC_MemoryExhausted;
    
    memcpy(infoStr, bufPtr, infoLength);
    
    if (someConditionThatCouldFail()) {
        // Memory leak: infoStr is not freed before returning error code
        return EC_SomeErrorCondition;
    }
    
    // ... process infoStr ...

    free(infoStr);
    return EC_Normal;
}