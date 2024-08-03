void rotate_image(uint8_t *src, uint8_t *dst, int width, int height, int angle) {
    int i, j;
    double radians = angle * 3.14159265 / 180.0;
    int new_width = height * fabs(sin(radians)) + width * fabs(cos(radians));
    int new_height = height * fabs(cos(radians)) + width * fabs(sin(radians));

    for (i = 0; i < new_height; i++) {
        for (j = 0; j < new_width; j++) {
            int x = (int)(j * cos(radians) + i * sin(radians));
            int y = (int)(-j * sin(radians) + i * cos(radians));
            x = x < width ? x : width - 1;
            y = y < height ? y : height - 1;
            dst[i * new_width + j] = src[y * width + x];
        }
    }
}