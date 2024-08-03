static int handle_network_packet(AVCodecContext *avctx, AVFrame *frame, const uint8_t *packet_data, int packet_size) {
    int ret, payload_size = 0;

    if (packet_size < MIN_NETWORK_PACKET_SIZE) return packet_size;

    payload_size = process_packet_data(avctx, frame, packet_data, packet_size);
    
    if (payload_size <= 0) {
        av_log(avctx, AV_LOG_ERROR, "Packet processing error\n");
        return -1;
    }

    if (payload_size > packet_size) {
        av_log(avctx, AV_LOG_ERROR, "Packet over-read\n");
        return -1;
    }

    if (payload_size < packet_size) {
        av_log(avctx, AV_LOG_WARNING, "Packet under-read\n");
    }
    return payload_size;
}