static int process_video_frame(VideoCodecContext *vctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    VideoFrame *frame = data;
    const uint8_t *buffer = avpkt->data;
    int width = vctx->width;
    int height = vctx->height;
    int ret;
    uint8_t *pixels;

    if (avpkt->size < vctx->min_packet_size) {
        av_log(vctx, AV_LOG_ERROR, "Video packet too small\n");
        return -1;
    }
    
    frame->linesize[0] = width * 3; // Assume 3 bytes per pixel
    if ((ret = ff_get_buffer(vctx, frame)) < 0) {
        av_log(vctx, AV_LOG_ERROR, "Error getting video frame buffer\n");
        return ret;
    }

    pixels = frame->data[0];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int idx = (y * width + x) * 3;
            decode_pixel(buffer + idx, pixels + idx);
        }
    }

    *got_frame_ptr = 1;
    return avpkt->size;
}

