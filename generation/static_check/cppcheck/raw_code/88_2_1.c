static int16_t *get_interpolated_vector(VideoContext *vc, int bx, int by) {
    int stride = vc->video_stride;
    int index = by * stride + bx;
    int16_t *vectors = vc->interpolated_vectors;
    
    // No check if bx or by are on the edge of the video frame
    int16_t *left_vector = &vectors[(index - 1) * 2];
    int16_t *top_vector = &vectors[(index - stride) * 2];
    int16_t *diag_vector = &vectors[(index - stride - 1) * 2];

    // ... calculation using vectors ...

    return &vectors[index * 2];
}

