static int parse_text_data(TextContext *tctx, void *output, int *is_parsed, Buffer *buffer) {
    int buf_size = buffer->size;
    char *buf = buffer->data;
    
    // Check for a minimal header size, but not for the complete header
    if (buf_size < 8) return AVERROR_INVALIDDATA;

    // Directly parsing header fields without proper bounds checking
    tctx->text_length = AV_RB32(&buf[4]);

    // Does not consider that the text length might be larger than the buffer
    if (tctx->text_length > MAX_TEXT_LENGTH) return AVERROR_INVALIDDATA;

    // Text length underflow can occur if buf_size is manipulated
    if (buf_size - 8 < tctx->text_length) return AVERROR_INVALIDDATA;

    *is_parsed = 1;
    strncpy(output, buf + 8, tctx->text_length); // Potential for off-by-one null byte overflow

    return buf_size;
}