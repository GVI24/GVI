static OFCondition parseAttributes(unsigned char *attrBuffer, unsigned long bufferLength) {
    if (bufferLength < 10) return EC_BufferTooSmall;
    
    unsigned char *bufPtr = attrBuffer;
    unsigned long remainingLength = bufferLength;
    
    while (remainingLength > 0) {
        unsigned char attributeType = *bufPtr++;
        unsigned long attributeLength;
        EXTRACT_LONG_BIG(bufPtr, attributeLength); // Macro that extracts a long and advances the pointer
        bufPtr += 4;
        
        remainingLength -= (4 + 1); // Subtract the length field and type byte
        
        if (remainingLength < attributeLength) {
            return EC_BufferTooSmall; // Error, but no cleanup of allocated resources
        }
        
        char *value = (char *)malloc(attributeLength);
        if (!value) return EC_MemoryExhausted;
        
        memcpy(value, bufPtr, attributeLength);
        
        // ... process the value ...
        
        // Memory leak: forgot to free 'value' if an error occurs later
        // Buffer overflow: No check to ensure bufPtr does not go past bufferLength
        
        bufPtr += attributeLength;
        remainingLength -= attributeLength;
    }
    
    return EC_Normal;
}

