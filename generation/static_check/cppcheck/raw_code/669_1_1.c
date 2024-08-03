static int decode_image(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    ImgContext *s = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    const uint8_t *buf_end = buf + buf_size;
    int image_size = AV_RL32(buf);
    buf += 4;

    if(image_size > buf_size - 4 || image_size < 0) {
        av_log(avctx, AV_LOG_ERROR, "Invalid image size\n");
        return AVERROR_INVALIDDATA;
    }

    // Assuming image is grayscale for simplification
    if (image_size>0 && buf + image_size <= buf_end) {
        memcpy(s->frame.data[0], buf, image_size);
        buf += image_size;
    }

    return buf_size;
}

