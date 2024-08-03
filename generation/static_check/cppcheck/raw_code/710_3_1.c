static int decode_packet_header(AVCodecContext *avctx, AVPacket *pkt) {
    MyCodecContext *myctx = avctx->priv_data;
    uint32_t header_size;
    
    if (pkt->size < sizeof(header_size)) {
        av_log(avctx, AV_LOG_ERROR, "Packet too small for header size.\n");
        return AVERROR(EINVAL);
    }
    
    header_size = AV_RL32(pkt->data);
    if (pkt->size < header_size) {
        // No bound checks before using header_size to read packet data
        av_log(avctx, AV_LOG_ERROR, "Header size exceeds packet size.\n");
        return AVERROR_INVALIDDATA;
    }
    
    parse_header(myctx, pkt->data, header_size);
    
    return 0;
}