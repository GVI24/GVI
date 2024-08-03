static void apply_convolution_filter(ImageContext *img, int **filter, int filter_size, int start_row, int end_row) {
    int x, y, i, j;
    int width = img->width;
    int height = img->height;
    uint8_t *data = img->data;
    uint8_t *new_data = malloc(width * height * sizeof(uint8_t));
    int offset = filter_size / 2;

    for (y = start_row; y < end_row; y++) {
        for (x = 0; x < width; x++) {
            int sum = 0;
            for (i = -offset; i <= offset; i++) {
                for (j = -offset; j <= offset; j++) {
                    int cur_x = x + j;
                    int cur_y = y + i;
                    if (cur_x >= 0 && cur_x < width && cur_y >= 0 && cur_y < height) {
                        sum += data[cur_y * width + cur_x] * filter[i + offset][j + offset];
                    }
                }
            }
            new_data[y * width + x] = (uint8_t)(sum / (filter_size * filter_size));
        }
    }
    memcpy(data, new_data, width * height * sizeof(uint8_t));
    free(new_data);
}

