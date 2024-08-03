static int decode_image(AVCodecContext *avctx, AVFrame *frame, const uint8_t *input, size_t input_size) {
    int ret;

    if ((ret = av_image_alloc(frame->data, frame->linesize, avctx->width, avctx->height, avctx->pix_fmt, 32)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "Cannot allocate image\n");
        return ret; // possible memory leak if av_image_alloc partially succeeded
    }

    // Simulate decoding process without checking return status
    ret = decode_custom_format(input, input_size, frame->data[0], avctx->width * avctx->height);
    if (ret < 0) {
        // No error handling or cleanup here
    }

    return 0;
}

