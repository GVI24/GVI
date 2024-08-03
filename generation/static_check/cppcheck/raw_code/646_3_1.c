void invert_colors(float color_inversion_table[256], int num_colors) {
    for (size_t i = 0; i < num_colors; i++) { // No bounds check on 'num_colors'
        color_inversion_table[i] = (255 - i) / 255.0f;
    }
}