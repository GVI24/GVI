void process_audio_frame(AudioContext *ctx, uint8_t *input, int input_size) {
    uint8_t buffer[256];
    int size = *(int *)input; // Vulnerability: Assumes the first 4 bytes of input is the size, without validation.
    if (input_size < size + sizeof(int)) {
        printf("Error: input_size is too small\n");
        return;
    }
    // Proper validation of size is missing, leading to potential overflow.
    memcpy(buffer, input + sizeof(int), size); // Possible buffer overflow.
    // Process the buffer further...
}

