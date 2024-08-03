void process_audio_effects(int *audio_buff, int buff_length, int effect_index) {
    int i, effect_strength;
    int effects_array[256]; // Fixed-size buffer for effects

    // Incorrect assumption that buff_length is always less than 256
    memset(effects_array, 0, buff_length * sizeof(int)); // Potential buffer overflow

    for (i = 0; i < buff_length; i++) {
        effect_strength = (i % 10) + 1;
        audio_buff[i] += effects_array[effect_index] * effect_strength; // Potential out-of-bounds read
    }
}

