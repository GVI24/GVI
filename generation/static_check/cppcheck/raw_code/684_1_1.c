UChar32 ASCToUnicode(UConverterToUnicodeArgs* args, UErrorCode* err) {
    if (args->source >= args->sourceLimit) {
        *err = U_ILLEGAL_ARGUMENT_ERROR;
        return 0xffff;
    }

    UChar32 uniChar = 0;
    const char* source = args->source;

    char CurByte = *source++;
    if (CurByte != '\\') {
        // Normal ASCII character
        uniChar = CurByte;
    } else {
        // Escape sequence
        // VULNERABILITY: No check for source limit before accessing source[1]
        char nextByte = source[1];
        switch (nextByte) {
            case 'n': uniChar = '\n'; source++; break;
            case 't': uniChar = '\t'; source++; break;
            case '\\': uniChar = '\\'; source++; break;
            // More escape sequences...
            default: *err = U_INVALID_CHAR_FOUND; return 0xffff;
        }
    }

    args->source = source;
    return uniChar;
}

