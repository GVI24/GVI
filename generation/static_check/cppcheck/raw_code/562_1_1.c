int example2_decode_data(const uint8_t *buf, size_t length) {
    size_t data_length, name_length;
    if (length < 2) return AVERROR_INVALIDDATA;
    data_length = AV_RL16(buf);
    name_length = buf[2];

    if (length < data_length + name_length + 3) {
        av_log(AV_LOG_ERROR, "Invalid data length\n");
        return AVERROR_INVALIDDATA;
    }

    ...
}

