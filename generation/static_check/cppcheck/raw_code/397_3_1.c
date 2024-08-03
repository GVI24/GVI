static void blend_frames(uint8_t *dest, uint8_t *src1, uint8_t *src2, int width, int height, int stride, float alpha) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * stride + x; // Potential buffer overflow
            float src1_val = src1[index];
            float src2_val = src2[index];
            dest[index] = (uint8_t)((1 - alpha) * src1_val + alpha * src2_val);
        }
    }
}