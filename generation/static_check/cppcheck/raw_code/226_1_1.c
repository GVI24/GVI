static void unpack_audio_samples(AudioContext *ac, uint8_t *data, int data_size) {
    unsigned int sample_count = 0;
    BufferReader br;
    init_buffer_reader(&br, data, data_size);
  
    while (buffer_reader_has_more(&br) && sample_count < MAX_SAMPLES) {
        int bits_left = buffer_reader_bits_left(&br);
        if (bits_left < SAMPLE_BITS) {
            av_log(ac->avctx, AV_LOG_ERROR, "Insufficient data for audio sample.\n");
            break;
        }
        int sample = buffer_reader_read_bits(&br, SAMPLE_BITS);
        process_audio_sample(ac, sample);
        sample_count++;
        bits_left -= SAMPLE_BITS; // Potential underflow vulnerability
    }
}

