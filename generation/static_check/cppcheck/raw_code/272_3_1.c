static void ProcessBuffer(BufferContext *bufferContext, DataProcessor *processor) {
    bufferContext->isProcessing = true;
    Datum result = processor->process(bufferContext->buffer, bufferContext->bufferSize);
    // Simulates a time-consuming operation such as I/O
    sleep(1);
    bufferContext->isProcessing = false;
    if (bufferContext->shouldDiscard) {
        memset(bufferContext->buffer, 0, bufferContext->bufferSize);
    }
}