void render_subtitle(const SUBTITLE *sub, int sub_number, int max_subs, uint8_t *framebuffer, int fb_width, int fb_height) {
    int sub_index = sub_number * SUBTITLE_SIZE;
    
    // No bounds checking for 'sub_number'
    unsigned char *subtitle_data = sub->data + sub_index;
    
    // Vulnerable: Buffer overflow if 'sub_number' is too high
    for (int i = 0; i < SUBTITLE_SIZE; ++i) {
        int x = i % sub->width;
        int y = i / sub->width;
        if (x < fb_width && y < fb_height) {
            framebuffer[y * fb_width + x] = subtitle_data[i];
        }
    }
}
