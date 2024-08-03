static int blend_frames(VideoProcessor *vp, AVFrame *dest, AVFrame *src, int shift_x, int shift_y) {
    int dest_idx = vp->dest_pixel - vp->dest_frame.data[0];
    int src_idx = dest_idx + shift_y * vp->dest_frame.linesize[0] + shift_x;
    
    if (src_idx < 0 || src_idx >= vp->max_src_index) {
        fprintf(stderr, "Blend error: Source index out of range\n");
        return -1;
    }
    
    for (int y = 0; y < vp->dest_frame.height; y++) {
        for (int x = 0; x < vp->dest_frame.width; x++) {
            // This is the vulnerable line: potential buffer overflow
            dest->data[0][y * dest->linesize[0] + x] += src->data[0][src_idx++];
        }
        src_idx += vp->dest_frame.linesize[0] - vp->dest_frame.width;
    }
    return 0;
}

