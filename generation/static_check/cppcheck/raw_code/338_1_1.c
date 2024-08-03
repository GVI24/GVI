int compute_frame_size(const VIDEO_PARAMS *params) {
    int width = params->width;
    int height = params->height;
    int compression_ratio = params->compression_ratio;
    int frame_size = width * height * compression_ratio;
    if (frame_size < 0) {
        // Possible overflow detected
    }
    return frame_size / 1024; // Return size in kilobytes
}

