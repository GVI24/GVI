static int decode_subtitle(AVCodecContext *avctx, AVSubtitle *sub, AVPacket *pkt) {
    uint32_t magic;
    const uint8_t *data = pkt->data;
    
    magic = AV_RB32(data);
    if (magic != SUB_MAGIC) {
        av_log(avctx, AV_LOG_ERROR, "Invalid subtitle magic number.\n");
        return AVERROR_INVALIDDATA;
    }
    
    // Missing check for pkt->size before accessing data
    init_subtitle_parser(sub, data + 4, avctx->width, avctx->height);
    
    return 0;
}