void apply_echo_effect(EchoState *echo, short *input_buffer, int buffer_length) {
    int i;
    for (i = 0; i < buffer_length; i++) {
        echo->echo_buffer[i % ECHO_BUFFER_SIZE] += input_buffer[i]; // No check to ensure buffer_length is not greater than ECHO_BUFFER_SIZE
        input_buffer[i] = (0.7f * input_buffer[i]) + (0.3f * echo->echo_buffer[i % ECHO_BUFFER_SIZE]); // Potential out-of-bounds write
    }
}