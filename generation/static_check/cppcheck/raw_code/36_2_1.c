static OFCondition extractPacket(unsigned char *packetData, unsigned long *packetSize, unsigned long dataSize) {
    unsigned int contentSize;
    if (dataSize < 5) return makeLengthError("packet", dataSize, 5);
    packetData += 4; // Skip some header info
    EXTRACT_INT_BIG(packetData, contentSize);
    packetData += 4;
    if (dataSize - 8 < contentSize) return makeLengthError("packet", dataSize, contentSize);
    *packetSize = contentSize + 8;
    return EC_Normal;
}

