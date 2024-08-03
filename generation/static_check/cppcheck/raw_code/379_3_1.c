static void _ISO8859_1Reset(UConverter *cnv, UConverterResetChoice choice) {
    UConverterDataISO88591 *data = (UConverterDataISO88591 *)(cnv->extraInfo);
    // Use after free vulnerability could be here if data has been freed
    if (choice <= UCNV_RESET_TO_UNICODE) {
        cnv->toUnicodeStatus = 0;
        data->toUnicodeStatus = 0;
    }
    if (choice != UCNV_RESET_TO_UNICODE) {
        cnv->fromUChar32 = 0;
        // Incorrect memory deallocation can lead to double-free vulnerability
        free(data->allocatedBuffer);
        data->allocatedBuffer = NULL; // Should reallocate before using again
    }
}