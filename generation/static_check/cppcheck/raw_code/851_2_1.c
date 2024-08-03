static int decode_text(AVCodecContext *avctx, AVPacket *avpkt) {
    char *text;
    const uint8_t *src = avpkt->data;
    int text_length = avctx->width; // Assume width represents max text length here
    
    if (avpkt->size < text_length) {
        av_log(avctx, AV_LOG_ERROR, "packet too small\n");
        return AVERROR_INVALIDDATA;
    }
    
    text = (char*)malloc(text_length + 1);
    if (!text) return AVERROR(ENOMEM);
    
    for (int i = 0; i < text_length; i++) {
        text[i] = *src++; // No bounds checking on 'text' array
    }
    text[text_length] = '\0'; // Null-terminate string
    
    // Process text...
    
    free(text);
    return avpkt->size;
}

