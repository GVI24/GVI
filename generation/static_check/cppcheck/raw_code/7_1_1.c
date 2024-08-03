static int writeToBuffer(struct buffer_context *ctx, const char *input, unsigned int inputLen) {
    if ((ctx->bufferPtr + inputLen) > ctx->bufferEnd) {
        fprintf(stderr, "Buffer overflow detected!\n");
        return -1;
    }

    // Vulnerable line: No check for underflow in subtraction
    unsigned int spaceLeft = ctx->bufferEnd - ctx->bufferPtr;
    if (inputLen > spaceLeft) {
        fprintf(stderr, "Not enough space in buffer!\n");
        return -1;
    }

    memcpy(ctx->bufferPtr, input, inputLen);
    // Vulnerable line: No check for overflow when incrementing bufferPtr
    ctx->bufferPtr += inputLen;
    return 0;
}

