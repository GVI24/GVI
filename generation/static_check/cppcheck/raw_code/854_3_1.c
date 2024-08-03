static void analyze_frame_contrast(VideoContext *vid_ctx, unsigned int *contrast) {
    // potentially large numbers, could overflow
    unsigned int avg_lum = vid_ctx->avg_luminance;
    unsigned int peak_lum = vid_ctx->peak_luminance;

    // unsafe arithmetic operations could lead to overflow
    *contrast = (peak_lum - avg_lum) * (peak_lum + avg_lum); // potential overflow
    *contrast >>= 8; // bit shift might not be appropriate for overflowed value
}