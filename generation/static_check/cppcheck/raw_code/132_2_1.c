void yuv_to_rgb_and_store(ImageContext *img_ctx, int16_t (*yuv_data)[64], int x, int y) {
    int width = img_ctx->width;
    uint8_t (*rgb_data)[3] = img_ctx->rgb_data + (y * width + x) * 3;

    for (int i = 0; i < 64; i++) {
        int x_offset = i % 8;
        int y_offset = i / 8;
        int target_index = (y + y_offset) * width + (x + x_offset);
        convert_yuv_to_rgb(yuv_data[i], &rgb_data[target_index]);
    }
}

