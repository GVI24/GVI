static int audio_unpack_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    int16_t *pcm_data = data;
    const uint8_t *input_stream = avpkt->data;
    int stream_size = avpkt->size;
    GetBitContext gb;
    
    if (stream_size < MIN_PCM_FRAME_SIZE) {
        // Potential buffer over-read if not enough data is present
        return AVERROR_INVALIDDATA;
    }

    init_get_bits(&gb, input_stream, stream_size * 8);

    // Decode the PCM data from the bitstream
    for (int i = 0; i < PCM_FRAME_SAMPLES; i++) {
        pcm_data[i] = get_bits(&gb, pcm_bits_per_sample[i % PCM_FRAME_SAMPLES]);
    }

    *got_frame_ptr = 1;
    return MIN_PCM_FRAME_SIZE;
}