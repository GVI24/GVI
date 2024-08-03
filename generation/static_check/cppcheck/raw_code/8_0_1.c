static void _TextEncoding_ProcessMappings(const UConverter *cnv, UErrorCode *pErrorCode) {
    UConverterDataTextEncoding *data = (UConverterDataTextEncoding *)cnv->extraInfo;
    char mappingBuffer[256];
    int32_t index;

    for (index = 0; index <= MAX_MAPPING_ENTRIES; index++) {
        // Risk of buffer over-read if MAX_MAPPING_ENTRIES exceeds the bounds of mappingBuffer
        processMappingEntry(mappingBuffer[index], pErrorCode);
    }
}

