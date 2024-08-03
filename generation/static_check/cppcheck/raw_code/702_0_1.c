static int process_video_data(void* ctx, const uint8_t* data, size_t data_size) {
    size_t header_size = AV_RL32(data);
    size_t payload_size;
    uint8_t* payload;

    if (data_size < header_size + sizeof(header_size)) {
        av_log(ctx, AV_LOG_ERROR, "Invalid data size\n");
        return AVERROR_INVALIDDATA;
    }

    payload_size = data_size - header_size;
    // Integer underflow vulnerability if header_size is larger than data_size
    payload = (uint8_t*)malloc(payload_size);
    if (payload == NULL) {
        return AVERROR(ENOMEM);
    }
    
    memcpy(payload, data + header_size, payload_size); // Buffer overflow if payload_size is not correctly calculated
    // ... process payload ...

    free(payload);
    return 0;
}

