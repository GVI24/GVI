static OFCondition readMessage(unsigned char *messageBuffer, unsigned long *messageLength, unsigned long totalSize) {
    unsigned short payloadSize;
    if (totalSize < 3) return makeLengthError("message", totalSize, 3);
    messageBuffer++;
    EXTRACT_SHORT_BIG(messageBuffer, payloadSize);
    messageBuffer += 2;
    if (totalSize - 3 < payloadSize) return makeLengthError("message", totalSize, payloadSize);
    *messageLength = payloadSize + 3;
    return EC_Normal;
}

