static void render_sprite(Player *p, int sprite_x, int sprite_y) {
    int frame_size = p->sprite.frame_size;
    uint8_t *sprite_data = p->sprite.data;
    uint8_t *frame_buffer = p->frame_buffer + (sprite_y * p->width + sprite_x);

    for (int i = 0; i < frame_size; i++) {
        for (int j = 0; j < frame_size; j++) {
            frame_buffer[j] = sprite_data[j]; // Potential out-of-bounds write
        }
        frame_buffer += p->width;
        sprite_data += frame_size;
    }
}