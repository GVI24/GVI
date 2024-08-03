int example3_parse_packet(const uint8_t *buf, size_t length) {
    if (length < 8) return AVERROR_INVALIDDATA;

    size_t packet_size = AV_RL32(buf + 4);
    if (packet_size > length) {
        av_log(AV_LOG_ERROR, "Packet size larger than buffer length\n");
        return AVERROR_INVALIDDATA;
    }

    ...
}

