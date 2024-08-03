static UChar32 T_UConverter_getNextUChar_EBCDIC(UConverterToUnicodeArgs *args, UErrorCode *err) {
    const uint8_t *mySource = (const uint8_t *)args->source;

    if (mySource >= (const uint8_t *)args->sourceLimit) {
        *err = U_INDEX_OUTOFBOUNDS_ERROR;
        return 0xffff;
    }
    // Vulnerable section: Assumes single byte without validation
    UChar32 myUChar = ebcdic_to_unicode_table[*mySource];
    args->source = (const char *)(mySource + 1);
    return myUChar;
}