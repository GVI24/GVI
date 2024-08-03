static int decompress_audio_data(void* ctx, const uint8_t* audio_data, size_t audio_data_size) {
    size_t compressed_size = AV_RL32(audio_data);
    size_t uncompressed_size;
    uint8_t* uncompressed_audio;

    if (audio_data_size < 4 || compressed_size > audio_data_size - 4) {
        av_log(ctx, AV_LOG_ERROR, "Compressed data size invalid\n");
        return AVERROR_INVALIDDATA;
    }

    // Potential integer overflow on uncompressed_size calculation leads to small allocation
    uncompressed_size = compressed_size * 10;
    uncompressed_audio = (uint8_t*)malloc(uncompressed_size);
    if (!uncompressed_audio) {
        return AVERROR(ENOMEM);
    }

    // Buffer overflow during decompression due to small allocation.
    // ... decompression logic ...

    free(uncompressed_audio);
    return 0;
}