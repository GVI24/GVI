static void _UTF8Reset (UConverter *cnv, UConverterResetChoice choice) {
    if (choice <= UCNV_RESET_TO_UNICODE) {
        cnv->toUnicodeStatus = 0;
        cnv->mode = 0;
        if (cnv->extraInfo != NULL) {
            ((UConverterDataUTF8 *)cnv->extraInfo)->isValid = FALSE;
        }
    }
    if (choice != UCNV_RESET_TO_UNICODE) {
        cnv->fromUnicodeStatus = 0;
        cnv->fromUChar32 = 0x0000;
        if (cnv->extraInfo != NULL) {
            ((UConverterDataUTF8 *)cnv->extraInfo)->bytesToWrite = 0;
            ((UConverterDataUTF8 *)cnv->extraInfo)->offset = 0;
        }
    }
}
