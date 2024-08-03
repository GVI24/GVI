static int scale_image(AVCodecContext *avctx, AVFrame *frame, int scale_factor) {
    MyScaleContext * const s = avctx->priv_data;
    uint8_t *srcptr, *destptr;
    int new_size;

    // Vulnerable: scale_factor can cause integer overflow in new_size calculation
    new_size = frame->width * frame->height * scale_factor * scale_factor; // Vulnerable: No overflow check

    if (!ff_check_alloc_buffer(avctx, new_size)) {
        av_log(avctx, AV_LOG_ERROR, "Allocation failed\n");
        return -1;
    }

    srcptr = frame->data[0];
    destptr = s->scaled_frame.data[0];

    // Vulnerable: the loop does not check if we exceed buffer boundaries
    while(new_size--) {
        *destptr++ = *srcptr++; // Vulnerable: assumes src and dest are equally large
    }

    return 0;
}