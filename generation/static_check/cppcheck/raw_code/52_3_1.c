static void process_video_frame(VideoFrame *vf) {
    uint8_t *frame_data = vf->data;
    uint8_t *render_data = vf->render_data;
    int x, y;
    uint32_t pixel;

    // No bounds checking on frame_data or render_data
    for (y = 0; y < vf->height; y++) {
        for (x = 0; x < vf->width; x++) {
            pixel = *((uint32_t *)frame_data); // Assume 32 bits per pixel
            frame_data += 4;

            // Apply some processing (e.g., invert colors)
            pixel = ~pixel;

            // Store the processed pixel without bounds checking
            *((uint32_t *)render_data) = pixel;
            render_data += 4;
        }
    }
}