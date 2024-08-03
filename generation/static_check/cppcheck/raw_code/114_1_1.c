static void _Latin1Reset (UConverter *cnv, UConverterResetChoice choice) {
    if (choice <= UCNV_RESET_TO_UNICODE) {
        cnv->toUnicodeStatus = 0;
        cnv->mode = 1;
        if (cnv->extraInfo != NULL) {
            ((UConverterDataLatin1 *)cnv->extraInfo)->lastChar = 0;
        }
    }
    if (choice != UCNV_RESET_TO_UNICODE) {
        cnv->fromUnicodeStatus = 0;
        if (cnv->extraInfo != NULL) {
            ((UConverterDataLatin1 *)cnv->extraInfo)->bufferIndex = 0;
            ((UConverterDataLatin1 *)cnv->extraInfo)->pendingChar = 0;
        }
    }
}
