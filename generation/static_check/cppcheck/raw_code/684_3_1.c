UChar32 HexToUnicode(UConverterToUnicodeArgs* args, UErrorCode* err) {
    if (args->source + 1 >= args->sourceLimit) {
        *err = U_ILLEGAL_ARGUMENT_ERROR;
        return 0xffff;
    }

    UChar32 uniChar = 0;
    const char* source = args->source;

    if (isxdigit(source[0]) && isxdigit(source[1])) {
        // VULNERABILITY: No check for source limit before accessing source[2]
        char hexBytes[] = { source[0], source[1], '\0' };
        uniChar = (UChar32)strtol(hexBytes, NULL, 16);
        source += 2;
    } else {
        *err = U_INVALID_CHAR_FOUND;
        return 0xffff;
    }

    args->source = source;
    return uniChar;
}