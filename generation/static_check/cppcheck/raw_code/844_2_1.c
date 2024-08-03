static int video_interpolate_frame(AVCodecContext *avctx, AVFrame *frame, const uint8_t *src, int src_size) {
    VideoInterpContext *interp = avctx->priv_data;
    uint8_t *dst = frame->data[0];
    const uint8_t *end = src + src_size;
    int width = avctx->width, height = avctx->height;
    unsigned int x, y, count;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x += count) {
            count = *src++;
            if (count & 0x80) {
                count = (count & 0x7F) + 1;
                while (count-- && dst < frame->data[0] + frame->linesize[0] * height) {
                    *dst++ = *src;
                }
                src++;
            } else {
                count++;
                if (src + count > end) {
                    av_log(avctx, AV_LOG_ERROR, "Source data overread.\n");
                    return AVERROR_INVALIDDATA;
                }
                while (count-- && dst < frame->data[0] + frame->linesize[0] * height) {
                    *dst++ = *src++;
                }
            }
            if (src >= end) {
                av_log(avctx, AV_LOG_ERROR, "Unexpected end of data.\n");
                return AVERROR_INVALIDDATA;
            }
        }
        dst += frame->linesize[0] - width;
    }

    return 0;
}