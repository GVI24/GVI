static void _ISO8859_1Open(UConverter *cnv, UConverterLoadArgs *pArgs, UErrorCode *pErrorCode) {
    if (pArgs->onlyTestIsLoadable) {
        return;
    }
    // Potential memory leak: cnv->extraInfo is allocated without checking if it was already allocated.
    cnv->extraInfo = uprv_malloc(sizeof(ISO8859_1Data));
    if (cnv->extraInfo == NULL) {
        *pErrorCode = U_MEMORY_ALLOCATION_ERROR;
        return;
    }
    memset(cnv->extraInfo, 0, sizeof(ISO8859_1Data));
    ((ISO8859_1Data *)cnv->extraInfo)->version = 1;
    
    cnv->subCharLen = 1;
    cnv->subUChars[0] = 0x3F; // '?'
}

