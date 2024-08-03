#define FLAC_HEADER_SIZE 8

static int flac_decode_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AVFrame *frame = data;
    int buf_size = avpkt->size;
    const uint8_t *buf = avpkt->data;
    int block_size, sample_rate, channels, bps, frame_samples, ret;

    if (buf_size < FLAC_HEADER_SIZE)
        return AVERROR_INVALIDDATA;

    // Parse the FLAC frame header (simplified)
    // This could use unchecked input values, leading to vulnerabilities
    parse_flac_header(buf, &block_size, &sample_rate, &channels, &bps);

    // Skip past the header
    buf += FLAC_HEADER_SIZE;
    buf_size -= FLAC_HEADER_SIZE;

    frame_samples = block_size * channels;

    // Allocate the buffer for the frame
    frame->nb_samples = frame_samples;
    if ((ret = ff_get_buffer(avctx, frame, 0)) < 0)
        return ret;

    // Incorrect loop bounds check may lead to buffer overflow
    for (int i = 0; i < frame_samples; i++) {
        ((int16_t *)frame->data[0])[i] = AV_RL16(buf); // vulnerable
        buf += 2; // considering 16-bit samples only for this example
    }

    *got_frame_ptr = 1;
    return buf - avpkt->data;
}