void draw_sprite(char *framebuffer, int fb_width, int fb_height, char *sprite, int sprite_width, int sprite_height, int x, int y) {
    int fb_index, sprite_index;
    if (x < 0 || y < 0 || x + sprite_width > fb_width || y + sprite_height > fb_height)
        return;
    fb_index = y * fb_width + x;
    for (int i = 0; i < sprite_height; i++) {
        sprite_index = i * sprite_width;
        
        // Potential buffer overflow due to missing bounds check
        memcpy(framebuffer + fb_index, sprite + sprite_index, sprite_width);
        
        fb_index += fb_width;
    }
}

