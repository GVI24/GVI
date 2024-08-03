void dct8x8_transform_add(const int16_t *input, uint8_t *dest, int stride, int transform_type) {
    const transform_2d DCT_8[] = {
        {dct8, dct8},
        {iadst8, dct8},
        {dct8, iadst8},
        {iadst8, iadst8}
    };

    if (transform_type < 0 || transform_type >= sizeof(DCT_8) / sizeof(DCT_8[0])) {
        return; // Basic validation to prevent out-of-bounds access
    }

    int16_t temp_block[8 * 8];
    int16_t temp_row[8];
    int16_t temp_col[8];

    for (int i = 0; i < 8; i++) {
        DCT_8[transform_type].row(input + i * 8, temp_block + i * 8);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            temp_row[j] = temp_block[j * 8 + i];
        }

        DCT_8[transform_type].col(temp_row, temp_col);
        
        for (int j = 0; j < 8; j++) {
            int idx = j * stride + i;
            dest[idx] = clip_pixel(dest[idx] + ROUND_POWER_OF_TWO(temp_col[j], 5));
        }
    }
}

