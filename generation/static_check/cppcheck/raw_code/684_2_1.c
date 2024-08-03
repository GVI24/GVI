UChar32 CustomEncToUnicode(UConverterToUnicodeArgs* args, UErrorCode* err) {
    if (args->source >= args->sourceLimit) {
        *err = U_ILLEGAL_ARGUMENT_ERROR;
        return 0xffff;
    }

    UChar32 uniChar = 0;
    unsigned char* source = (unsigned char*)args->source;
    unsigned char CurByte = *source++;

    if (CurByte < 0x80) {
        // Single byte character
        uniChar = CurByte;
    } else {
        // Multibyte character indicator
        // VULNERABILITY: No check for source limit
        unsigned char secondByte = *source++;
        unsigned char thirdByte = *source++;
        uniChar = ((CurByte & 0x1F) << 12) | ((secondByte & 0x3F) << 6) | (thirdByte & 0x3F);
    }

    args->source = (const char*)source;
    return uniChar;
}

