static OFCondition parseHeader(unsigned char *buffer, unsigned long *headerSize, unsigned long maxBufferSize) {
    unsigned int nameSize;
    if (maxBufferSize < 2) return makeLengthError("header", maxBufferSize, 2);
    EXTRACT_INT_LITTLE(buffer, nameSize);
    buffer += 2;
    if (maxBufferSize - 2 < nameSize) return makeLengthError("header", maxBufferSize, nameSize);
    *headerSize = nameSize + 2;
    return EC_Normal;
}

