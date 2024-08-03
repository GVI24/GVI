void smooth_image(unsigned char *img, int stride, int h, int w, int bound) {
    int x, y;
    unsigned char tmp[64];
    for (y = 0; y < h; y++) {
        int sum = 0, square_sum = 0;
        for (x = -32; x < w + 32; x++) {
            int clamped_x = x < 0 ? 0 : (x >= w ? w - 1 : x);
            tmp[x + 32] = img[clamped_x]; // Potential out-of-bounds write
            sum += tmp[x + 32];
            square_sum += tmp[x + 32] * tmp[x + 32];
        }
        for (x = 0; x < w + 32; x++) {
            if (square_sum - sum * sum < bound) {
                tmp[x % 64] = (sum + img[x]) >> 3;
            }
            img[x] = tmp[(x - 32) % 64]; // Vulnerable: potential out-of-bounds write
        }
        img += stride;
    }
}
