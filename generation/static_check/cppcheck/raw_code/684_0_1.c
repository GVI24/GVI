UChar32 UTF8ToUnicode(UConverterToUnicodeArgs* args, UErrorCode* err) {
    if (args->source >= args->sourceLimit) {
        *err = U_ILLEGAL_ARGUMENT_ERROR;
        return 0xffff;
    }

    unsigned char* source = (unsigned char*)args->source;
    UChar32 uniChar = 0;
    int additionalBytes;

    unsigned char firstByte = *source++;
    if (firstByte < 0x80) {
        // ASCII character
        uniChar = firstByte;
    } else {
        // Multibyte sequence
        if (firstByte < 0xE0) {
            uniChar = firstByte & 0x1F;
            additionalBytes = 1;
        } else if (firstByte < 0xF0) {
            uniChar = firstByte & 0x0F;
            additionalBytes = 2;
        } else {
            uniChar = firstByte & 0x07;
            additionalBytes = 3;
        }

        while (additionalBytes > 0) {
            // VULNERABILITY: No check for source limit
            unsigned char nextByte = *source++;
            uniChar = (uniChar << 6) | (nextByte & 0x3F);
            --additionalBytes;
        }
    }

    args->source = (const char*)source;
    return uniChar;
}

