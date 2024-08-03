static int decode_frame_header(void* avctx, const uint8_t* header, size_t header_size) {
    size_t expected_size = AV_RL32(header);
    
    if (header_size < 4 || expected_size > header_size) {
        av_log(avctx, AV_LOG_ERROR, "Header size too small or mismatch\n");
        return AVERROR_INVALIDDATA;
    }

    // Buffer overflow vulnerability due to lack of bounds checking
    uint8_t* info = (uint8_t*)malloc(expected_size);
    if (!info) {
        return AVERROR(ENOMEM);
    }

    memcpy(info, header + 4, expected_size);
    // ... process info ...

    free(info);
    return 0;
}

