static int text_subtitle_decode(AVCodecContext *avctx, void *data, int *got_sub_ptr, AVPacket *avpkt) {
    AVSubtitle *sub = data;
    char *text = avpkt->data;
    unsigned text_size = avpkt->size;
    char *sub_text = av_malloc(text_size + 1); // +1 for null terminator

    if (!sub_text) {
        av_log(avctx, AV_LOG_ERROR, "Failed to allocate subtitle text buffer\n");
        return AVERROR(ENOMEM);
    }

    if (text_size > 0) {
        memcpy(sub_text, text, text_size);
        sub_text[text_size] = '\0'; // null terminate the string
    }

    sub->rects = av_mallocz(sizeof(*sub->rects));
    if (!sub->rects) {
        av_free(sub_text);
        av_log(avctx, AV_LOG_ERROR, "Failed to allocate subtitle rects\n");
        return AVERROR(ENOMEM);
    }

    sub->rects[0].text = sub_text;
    sub->num_rects = 1;
    *got_sub_ptr = 1;

    return text_size;
}