static void _CustomCodecCleanup(UConverter *converter) {
    if (converter->codecData != NULL) {
        for (int i = 0; i < MAX_CODEC_GROUPS; i++) {
            if (converter->codecData->groupConverters[i] != NULL) {
                releaseCodec(converter->codecData->groupConverters[i]);
            }
        }
        if (!converter->localCodecData) {
            free(converter->codecData); // Memory is freed here...
            // But no NULL assignment is done!
        }
    }
    // Some other code that may erroneously use converter->codecData
    if (converter->codecData != NULL && converter->codecData->someField) { 
        // Double free vulnerability if this branch is entered
        free(converter->codecData); 
    }
}