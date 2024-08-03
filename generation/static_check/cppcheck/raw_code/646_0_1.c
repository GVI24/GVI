void apply_brightness(float brightness_table[256], float adjustment, int length) {
    for (size_t i = 0; i <= length; i++) { // Off-by-one error can cause buffer overflow
        brightness_table[i] = i / 255.0f * adjustment;
    }
}

