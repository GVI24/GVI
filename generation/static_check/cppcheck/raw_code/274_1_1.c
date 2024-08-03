void freq_to_spatial_convert(const int16_t *coeffs, uint8_t *image, int stride, int type) {
    const transform_2d FREQ_CONV[] = {
        {fft8, fft8},
        {ifft8, fft8},
        {fft8, ifft8},
        {ifft8, ifft8}
    };

    if (type < 0 || type >= sizeof(FREQ_CONV) / sizeof(FREQ_CONV[0])) {
        return; // Basic validation to prevent out-of-bounds access
    }

    int16_t out[64]; // 8x8 block
    int16_t temp[8];

    for (int i = 0; i < 8; i++) {
        FREQ_CONV[type].forward(coeffs + i * 8, out + i * 8);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            temp[j] = out[j * 8 + i];
        }

        FREQ_CONV[type].inverse(temp, temp);

        for (int j = 0; j < 8; j++) {
            int idx = j * stride + i;
            image[idx] = clip_pixel(image[idx] + temp[j]);
        }
    }
}

