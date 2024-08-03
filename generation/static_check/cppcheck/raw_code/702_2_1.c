static int extract_metadata(void* ctx, const uint8_t* packet, size_t packet_size) {
    size_t meta_size = AV_RL32(packet);
    uint8_t* metadata_buffer;

    if (packet_size < 8 || meta_size > packet_size - 4) {
        av_log(ctx, AV_LOG_ERROR, "Packet size too small or metadata size too large\n");
        return AVERROR_INVALIDDATA;
    }

    // Memory corruption due to incorrect padding
    metadata_buffer = (uint8_t*)malloc(meta_size);
    if (!metadata_buffer) {
        return AVERROR(ENOMEM);
    }

    memset(metadata_buffer + meta_size, 0, FF_INPUT_BUFFER_PADDING_SIZE);
    memcpy(metadata_buffer, packet + 4, meta_size);
    // ... process metadata ...

    free(metadata_buffer);
    return 0;
}

