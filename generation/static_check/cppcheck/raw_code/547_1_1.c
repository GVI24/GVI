void process_audio_frame(int16_t *output, const int16_t *input, int input_size) {
    int index, echo_offset = 5;
    int16_t echo_buffer[256]; // Fixed size buffer
    
    if (input_size < echo_offset) return; // Not enough data

    // Copy with potential overflow if input_size is too high
    for (index = 0; index < input_size; index++) {
        echo_buffer[index] = input[index];
        if (index >= echo_offset) {
            output[index] = (input[index] + echo_buffer[index - echo_offset]) / 2;
        } else {
            output[index] = input[index];
        }
    }
}

