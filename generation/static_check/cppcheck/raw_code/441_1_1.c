static int image_decompress(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    ImageDecContext *s = avctx->priv_data;
    AVFrame *frame = data;
    int ret;

    if (s->decompressor.image_size > buf_size) {
        av_log(avctx, AV_LOG_ERROR, "Compressed image too small (%u, should be %u)\n", buf_size, s->decompressor.image_size);
        return AVERROR_INVALIDDATA;
    }

    if ((ret = ff_get_buffer(avctx, frame, 0)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }

    ImageDecompress(&s->decompressor, frame->data[0], buf);
    *got_frame_ptr = 1;
    return s->decompressor.image_size;
}