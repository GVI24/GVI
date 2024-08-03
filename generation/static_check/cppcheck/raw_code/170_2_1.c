static int text_subtitle_decode(AVCodecContext *avctx, void *data, int *got_sub_ptr, AVPacket *avpkt) {
    char *text = (char *)avpkt->data;
    SubtitleContext *sub_ctx = avctx->priv_data;

    if (!sub_ctx->buffer) {
        sub_ctx->buffer = malloc(avpkt->size); // Vulnerability: No check for malloc failure
    } else {
        sub_ctx->buffer = realloc(sub_ctx->buffer, avpkt->size); // Vulnerability: No check for realloc failure
    }

    memcpy(sub_ctx->buffer, text, avpkt->size); // Vulnerability: No bounds checking, potential buffer overflow
    
    *got_sub_ptr = 1;
    *(SubtitleFrame *)data = sub_ctx->buffer; // Vulnerability: Assuming data can hold a pointer

    return avpkt->size;
}