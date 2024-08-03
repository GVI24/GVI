void copy_video_frame(VideoFrame *src, VideoFrame *dst) {
    // Potential vulnerability: No check if src or dst is NULL before dereferencing
    memcpy(dst->buffer, src->buffer, src->width * src->height * sizeof(Pixel));
    dst->width = src->width;
    dst->height = src->height;
}

