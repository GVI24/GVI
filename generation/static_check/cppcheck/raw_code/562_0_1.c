int example1_decode_frame(const uint8_t *buf, int length) {
    int header_size;
    int payload_size;
    if (length < 4) return AVERROR_INVALIDDATA;
    header_size = buf[0];
    payload_size = buf[1];

    if (length < header_size + payload_size) {
        av_log(AV_LOG_ERROR, "Invalid header and payload size\n");
        return AVERROR_INVALIDDATA;
    }

    ...
}

