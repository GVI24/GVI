static UChar32 T_UConverter_getNextUChar_UTF8(UConverterToUnicodeArgs *args, UErrorCode *err) {
    const uint8_t *mySource = (const uint8_t *)args->source;
    UChar32 myUChar = 0;
    
    if (mySource >= (const uint8_t *)args->sourceLimit) {
        *err = U_INDEX_OUTOFBOUNDS_ERROR;
        return 0xffff;
    }
    // Vulnerable section: Does not check for correct UTF-8 sequence lengths
    unsigned char c = *mySource++;
    if (c < 0x80) {
        myUChar = c;
    } else if (c < 0xE0) {
        myUChar = ((c & 0x1F) << 6) | (*mySource & 0x3F);
        mySource += 1;
    } else if (c < 0xF0) {
        myUChar = ((c & 0x0F) << 12) | ((*mySource & 0x3F) << 6) | (mySource[1] & 0x3F);
        mySource += 2;
    }
    args->source = (const char *)mySource;
    return myUChar;
}

