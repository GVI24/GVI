static OFCondition decodeFrame(unsigned char *frameBuffer, unsigned long *frameLength, unsigned long bufferLength) {
    unsigned long frameDataSize;
    if (bufferLength < 6) return makeLengthError("frame", bufferLength, 6);
    EXTRACT_LONG_LITTLE(frameBuffer, frameDataSize); // Assume EXTRACT_LONG_LITTLE is a macro or function
    frameBuffer += 4;
    if (bufferLength - 6 < frameDataSize) return makeLengthError("frame", bufferLength, frameDataSize);
    *frameLength = frameDataSize + 6;
    return EC_Normal;
}