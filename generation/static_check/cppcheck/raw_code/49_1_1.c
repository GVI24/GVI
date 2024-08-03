static int video_process_frame(AVCodecContext *vctx, void *output, int *frame_ready, AVPacket *vpkt) {
    AVFrame *frame = output;
    uint8_t *input_data = vpkt->data;
    VideoProcessContext *vproc_ctx = vctx->priv_data;
    uint8_t *input_end = input_data + vpkt->size;
    uint8_t *frame_buffer;
    int ret;

    if ((ret = ff_get_buffer(vctx, frame)) < 0) {
        av_log(vctx, AV_LOG_ERROR, "Failed to get buffer for frame.\n");
        return ret;
    }

    frame_buffer = frame->data[0];
    while (input_data < input_end) {
        int pixel_value = video_pixel_transform(*input_data++); // No boundary check
        *frame_buffer++ = pixel_value; // Potential buffer overflow
    }

    *frame_ready = 1;
    return vpkt->size;
}

