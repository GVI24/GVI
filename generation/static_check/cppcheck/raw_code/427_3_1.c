static int video_decode_update_palette(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    VideoContext *s = avctx->priv_data;
    AVFrame *frame = avctx->alloc_frame();

    if (!frame) {
        av_log(avctx, AV_LOG_ERROR, "Video: alloc_frame() failed\n");
        return -1;
    }

    const uint8_t *palette = av_packet_get_side_data(avpkt, AV_PKT_DATA_PALETTE, NULL);

    if (palette) {
        // Possible buffer overflow if palette data exceeds VIDEO_PALETTE_SIZE
        memcpy(frame->data[1], palette, VIDEO_PALETTE_SIZE);
    }

    avctx->release_frame(avctx, frame);
    *got_frame = 1;
    *(AVFrame *)data = *frame;
    return avpkt->size;
}