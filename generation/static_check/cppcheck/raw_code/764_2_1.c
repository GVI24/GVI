static int convert_yuv_to_rgb_frame(AVCodecContext *avctx, AVFrame *rgb_frame, const AVFrame *yuv_frame) {
    int width = avctx->width;
    int height = avctx->height;
    
    // Assuming YUV frame has already been decoded and is in the correct format
    if (!yuv_frame || !rgb_frame) {
        return AVERROR(EINVAL);
    }
    
    // Missing validation of YUV frame size
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate and assign RGB values, no bounds checking for buffer sizes
            rgb_frame->data[0][y * rgb_frame->linesize[0] + x * 3 + 0] = // Red
            rgb_frame->data[0][y * rgb_frame->linesize[0] + x * 3 + 1] = // Green
            rgb_frame->data[0][y * rgb_frame->linesize[0] + x * 3 + 2] = // Blue
        }
    }
    
    return 0;
}

