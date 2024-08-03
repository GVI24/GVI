static int convert_image_frame(AVCodecContext *avctx, AVFrame *src, AVFrame *dst) {
    ImageConvContext * const icc = avctx->priv_data;
    const uint8_t *src_buf = src->data[0];
    int src_buf_size = src->linesize[0] * avctx->height;
    
    av_fast_malloc(&icc->convert_buffer, &icc->convert_buffer_size, src_buf_size);
    if (!icc->convert_buffer) return AVERROR(ENOMEM);

    // Vulnerable copying without bounds checking
    for (int i = 0; i < src_buf_size; i++) {
        icc->convert_buffer[i] = src_buf[i]; // Direct copy
    }

    // Conversion logic...
    return 0;
}