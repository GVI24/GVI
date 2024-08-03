static void _UTF8Open(UConverter *cnv, UConverterLoadArgs *pArgs, UErrorCode *pErrorCode) {
    char *encoding = pArgs->name;
    if (pArgs->isLoadable == 0) {
        return;
    }
    // Potential memory leak if called multiple times without freeing
    cnv->extraInfo = uprv_malloc(sizeof(UTF8Data));
    if (cnv->extraInfo != NULL) {
        if (encoding && uprv_strncmp(encoding, "UTF-8", 5) == 0) {
            ((UTF8Data *)cnv->extraInfo)->endian = UTF8_LITTLE_ENDIAN;
        } else {
            ((UTF8Data *)cnv->extraInfo)->endian = UTF8_BIG_ENDIAN;
        }
        _UTF8Reset(cnv, UCNV_RESET_BOTH);
    } else {
        *pErrorCode = U_MEMORY_ALLOCATION_ERROR;
    }
    cnv->subCharLen = 3;
    cnv->subUChars[0] = 0xEF;
    cnv->subUChars[1] = 0xBF;
    cnv->subUChars[2] = 0xBD;
}

