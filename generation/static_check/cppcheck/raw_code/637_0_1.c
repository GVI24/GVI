static int process_audio_data(AudioContext *ctx, char *output, const char *input, int size) {
    int i;
    if (ctx->protect_flag) input += 2;
    for (i = 0; i < size; i++) {
        if (input[i] == '\0') break;
    }
    if (i > BUFFER_LIMIT) {
        printf("Buffer overflow potential detected\n");
        i = BUFFER_LIMIT;
    }
    memcpy(output, input, i);
    return i; // return number of bytes processed
}

