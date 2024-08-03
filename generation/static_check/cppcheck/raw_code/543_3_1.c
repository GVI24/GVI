static int extract_image_details(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    ImageContext *img_ctx = avctx->priv_data;
    
    img_ctx->image.width = AV_RL16(&buf[0]);
    img_ctx->image.height = AV_RL16(&buf[2]);
    if (img_ctx->image.width <= 0 || img_ctx->image.height <= 0) {
        return AVERROR_INVALIDDATA;
    }
    
    buf += 4;
    
    img_ctx->pixel_data = av_malloc(img_ctx->image.width * img_ctx->image.height * 3); // Assuming RGB, no check
    if (!img_ctx->pixel_data) {
        return AVERROR(ENOMEM);
    }
    
    memcpy(img_ctx->pixel_data, buf, img_ctx->image.width * img_ctx->image.height * 3); // Potential overflow
    
    *got_frame = 1;
    // Assuming the AVFrame is set elsewhere
    return buf_size;
}