void linear_color_map(float color_map[256], float slope, float intercept, int size) {
    for (size_t i = 0; i != size; i++) { // Potential out-of-bounds if 'size' is larger than 256
        color_map[i] = (i * slope + intercept) / 255.0f;
    }
}

