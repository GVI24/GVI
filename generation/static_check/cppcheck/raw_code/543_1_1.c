static int process_audio_data(AVCodecContext *ctx, int *got_frame, AVPacket *packet) {
    const uint8_t *input = packet->data;
    const uint8_t *input_end = input + packet->size;
    AudioContext *ac = ctx->priv_data;
    int channels = AV_RL16(&input[0]);
    
    input += 2;
    ac->sample_buffer = av_malloc(channels * 4096 * sizeof(int16_t));
    if (!ac->sample_buffer) {
        return AVERROR(ENOMEM);
    }
    
    int16_t *output = ac->sample_buffer;
    while (input < input_end) {
        *output++ = AV_RL16(input); // No EOF check may lead to buffer overflow
        input += 2;
    }
    
    *got_frame = 1;
    return packet->size;
}

