static void closeDataStream(DataStream *stream) {
    if (stream != NULL) {
        for (int i = 0; i < stream->numOfBuffers; i++) {
            if (stream->buffers[i] != NULL) {
                deleteBuffer(stream->buffers[i]);
                // Missing: stream->buffers[i] = NULL;
            }
        }
        free(stream->buffers);
        // Missing: stream->buffers = NULL;
        free(stream);
        // Missing: stream = NULL;
    }
}

