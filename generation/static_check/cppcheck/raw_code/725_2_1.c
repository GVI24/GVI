static int subtitle_decode_frame(AVCodecContext *avctx, void *data, int *got_sub, AVPacket *avpkt) {
    SubtitleContext *sub = avctx->priv_data;
    int buf_size = avpkt->size;

    // Vulnerability: Unsafe allocation size could lead to integer overflow and small buffer allocation
    sub->text = malloc(buf_size + 1); // Plus one for null terminator
    if (sub->text == NULL) {
        return AVERROR(ENOMEM);
    }

    // Vulnerability: Buffer overflow if avpkt->data is not null-terminated
    strcpy(sub->text, (const char *)avpkt->data);

    // Further processing...
    // Vulnerability: No cleanup on failure path can cause memory leak
    if (process_failure_condition) {
        av_log(avctx, AV_LOG_ERROR, "Processing failed\n");
        *got_sub = 0;
        return -1; // Leak: sub->text is not freed
    }

    *got_sub = 1;
    *(AVSubtitle *)data = sub->subtitle;

    return buf_size;
}

