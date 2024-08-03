static void _SBCSReset (UConverter *cnv, UConverterResetChoice choice) {
    if (choice <= UCNV_RESET_TO_UNICODE) {
        cnv->toUnicodeStatus = 0;
        if (cnv->extraInfo != NULL) {
            ((UConverterDataSBCS *)cnv->extraInfo)->outputSequenceLength = 0;
        }
    }
    if (choice != UCNV_RESET_TO_UNICODE) {
        cnv->fromUnicodeStatus = 0;
        if (cnv->extraInfo != NULL) {
            ((UConverterDataSBCS *)cnv->extraInfo)->fallbackCounter = 0;
            ((UConverterDataSBCS *)cnv->extraInfo)->fallbackLimit = 1;
        }
    }
}
