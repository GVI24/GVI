static int scale_image(AVCodecContext *avctx, AVFrame *dest_frame, const AVFrame *src_frame) {
    int src_width = src_frame->width;
    int src_height = src_frame->height;
    int dest_width = dest_frame->width;
    int dest_height = dest_frame->height;
    
    // Assuming src_frame contains a valid image
    if (!dest_frame || !src_frame) {
        return AVERROR(EINVAL);
    }
    
    // No bounds checking for destination frame buffer size
    for (int y = 0; y < dest_height; y++) {
        for (int x = 0; x < dest_width; x++) {
            int src_x = x * src_width / dest_width;
            int src_y = y * src_height / dest_height;
            dest_frame->data[0][y * dest_frame->linesize[0] + x] = src_frame->data[0][src_y * src_frame->linesize[0] + src_x];
        }
    }
    
    return 0;
}