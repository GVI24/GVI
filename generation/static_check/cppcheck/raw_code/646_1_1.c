void generate_contrast_table(float contrast_table[256], float factor, int elements) {
    float midpoint = 0.5f;
    for (size_t i = 0; i < elements; i++) { // No bounds check for 'elements'
        float scale = (i / 255.0f - midpoint) * factor + midpoint;
        contrast_table[i] = scale > 1.0f ? 1.0f : (scale < 0.0f ? 0.0f : scale);
    }
}

