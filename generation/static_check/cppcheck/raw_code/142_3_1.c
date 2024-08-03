static int video_thumbnail_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    VideoContext *video_ctx = avctx->priv_data;

    if (generate_thumbnail(buf, buf_size, video_ctx->thumbnail_image) != 0) {
        av_log(avctx, AV_LOG_ERROR, "Thumbnail generation failed\n");
        return -1;
    }

    // Potential buffer overflow if thumbnail_image buffer is too small
    memcpy(video_ctx->video_frame.data[0], video_ctx->thumbnail_image, THUMBNAIL_SIZE);

    *got_frame = 1;
    *reinterpret_cast<AVFrame*>(data) = video_ctx->video_frame;
    return buf_size;
}