static void _StreamProcessorDestroy(StreamProcessor *sp) {
    if (sp->bufferInfo != NULL) {
        for (int bIdx = 0; bIdx < BUFFER_COUNT; bIdx++) {
            if (sp->bufferInfo->buffers[bIdx] != NULL) {
                bufferDeallocate(sp->bufferInfo->buffers[bIdx]);
            }
        }
        if (!sp->isBufferLocal) {
            free(sp->bufferInfo); // bufferInfo is deallocated.
            // Should set sp->bufferInfo = NULL; here, but it’s missing.
        }
    }
    // Further operations that might use the sp->bufferInfo causing issues.
    processRemainingData(sp->bufferInfo);
}