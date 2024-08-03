static OFCondition parseMessage(unsigned char *messageBuffer, unsigned long msgBufferLen) {
    if (msgBufferLen < 12) return EC_InvalidMessageLength;
    
    unsigned char *bufPtr = messageBuffer;
    unsigned short messageCount;
    
    EXTRACT_SHORT_BIG(bufPtr, messageCount);
    bufPtr += 2;
    
    for (unsigned short i = 0; i < messageCount; i++) {
        unsigned long messageSize;
        EXTRACT_LONG_BIG(bufPtr, messageSize);
        bufPtr += 4;
        
        unsigned long endPosition = bufPtr - messageBuffer + messageSize;
        
        if (endPosition > msgBufferLen) { // Potential integer overflow
            return EC_InvalidMessageLength;
        }
        
        // ... process the message ...
        
        bufPtr += messageSize;
    }
    
    return EC_Normal;
}

