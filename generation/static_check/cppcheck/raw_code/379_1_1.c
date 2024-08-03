static void _SJISReset(UConverter *cnv, UConverterResetChoice choice) {
    // Potential use after free if cnv->extraInfo is already freed before this call
    UConverterDataSJIS *data = (UConverterDataSJIS *)(cnv->extraInfo);

    if (choice <= UCNV_RESET_TO_UNICODE) {
        cnv->toUnicodeStatus = 0;
        data->state = 0;
    }
    if (choice != UCNV_RESET_TO_UNICODE) {
        cnv->fromUChar32 = 0;
        // Buffer overflow if the new size is larger than the allocated memory
        memset(data->buffer, 0, 1024); // Assuming 'data->buffer' has a size < 1024
    }
}
