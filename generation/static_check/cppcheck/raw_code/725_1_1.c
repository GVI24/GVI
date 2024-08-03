static int video_scale_frame(AVCodecContext *avctx, void *data, AVFrame *src_frame) {
    int src_w = avctx->width;
    int src_h = avctx->height;
    int dst_w = src_w / 2;
    int dst_h = src_h / 2;
    VideoScalerContext *scaler = avctx->priv_data;

    // Vulnerability: Unchecked malloc without initialization
    scaler->scaled_frame_data = malloc(dst_w * dst_h * 3); // for RGB data
    if (!scaler->scaled_frame_data) {
        return AVERROR(ENOMEM);
    }

    // Vulnerability: Potential off-by-one error leading to buffer overflow
    for (int y = 0; y <= dst_h; y++) {
        for (int x = 0; x <= dst_w; x++) {
            // Perform scaling operation (susceptible to buffer overflow)
            int src_index = (y * 2 * src_w + x * 2) * 3;
            int dst_index = (y * dst_w + x) * 3;
            scaler->scaled_frame_data[dst_index] = src_frame->data[0][src_index];
        }
    }

    // Set output data
    // Vulnerability: Missing error handling and resource cleanup
    *(AVFrame *)data = scaler->scaled_frame;

    return 0;
}

