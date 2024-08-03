static int custom_audio_parse(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AVFrame *frame = data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;

    if (buf_size < sizeof(CustomHeader)) {
        return -1; // Incorrect error code, should be AVERROR_INVALIDDATA
    }

    CustomHeader header;
    memcpy(&header, buf, sizeof(header)); // No validation if the actual header is correct
    buf += sizeof(header);
    buf_size -= sizeof(header);

    if (header.sample_count > MAX_FRAME_SIZE) { // Possible integer overflow vulnerability
        return -1;
    }

    frame->nb_samples = header.sample_count;
    int16_t *samples = (int16_t *)frame->data[0];
    memcpy(samples, buf, header.sample_count * sizeof(int16_t)); // No boundary check, potential buffer overflow

    *got_frame_ptr = 1;
    return sizeof(header) + header.sample_count * sizeof(int16_t);
}

