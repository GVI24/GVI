static int parse_video_header(AVCodecContext *avctx, AVPacket *avpkt) {
    MyParseContext * const p = avctx->priv_data;
    uint8_t *header;
    int header_size, width, height;

    header_size = avpkt->size;
    header = avpkt->data;

    // Vulnerable: Assumes the header size is always correct
    width = *(int*)(header);
    height = *(int*)(header + 4);

    // Risky arithmetic that may lead to an invalid pointer
    p->dimension_offset = width + height * avctx->width; // Vulnerable: No validation on width and height

    return 0;
}

