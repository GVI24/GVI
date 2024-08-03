static void _DBCSReset (UConverter *cnv, UConverterResetChoice choice) {
    if (choice <= UCNV_RESET_TO_UNICODE) {
        cnv->toUnicodeStatus = 0;
        if (cnv->extraInfo != NULL) {
            ((UConverterDataDBCS *)cnv->extraInfo)->sequenceLength = 0;
            ((UConverterDataDBCS *)cnv->extraInfo)->sequencePos = 0;
        }
    }
    if (choice != UCNV_RESET_TO_UNICODE) {
        cnv->fromUnicodeStatus = 0;
        cnv->fromUChar32 = 0x0000;
        if (cnv->extraInfo != NULL) {
            ((UConverterDataDBCS *)cnv->extraInfo)->startRange = 0x40;
            ((UConverterDataDBCS *)cnv->extraInfo)->endRange = 0xFE;
        }
    }
}