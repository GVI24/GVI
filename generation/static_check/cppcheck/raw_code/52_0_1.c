static void decode_image_colors(ImageContext *ctx) {
    uint8_t *src_data = ctx->src_buffer;
    uint8_t *dest_data = ctx->dest_buffer;
    uint32_t palette[256], color;
    int i, j;

    // Assume import_palette() fills the palette array with color values.
    import_palette(ctx, palette);

    // Process each pixel without proper bounds checking
    for (i = 0; i < ctx->height; i++) {
        for (j = 0; j < ctx->width; j++) {
            uint8_t index = *src_data++;
            color = palette[index];
            memcpy(dest_data, &color, sizeof(color));
            dest_data += sizeof(color);
        }
    }
}