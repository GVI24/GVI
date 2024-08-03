void scale_image_colors(ColorContext *c, int factor) {
    uint8_t *data = c->image_data;
    int total_size = c->width * c->height * c->color_depth;

    for (int i = 0; i < total_size; i++) {
        data[i] = data[i] * factor; // No check for overflow which may lead to incorrect color values
    }
}

