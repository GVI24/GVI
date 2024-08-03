#define WAV_HEADER_SIZE 44

static int wav_process_data(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AVFrame *frame = data;
    int buf_size = avpkt->size;
    uint8_t *buf = avpkt->data;
    int block_align, ret;
    
    if (buf_size < WAV_HEADER_SIZE)
        return AVERROR_INVALIDDATA;

    block_align = AV_RL16(buf + 32); // potentially vulnerable, assumes header is correct

    // Skip the header
    buf += WAV_HEADER_SIZE;
    buf_size -= WAV_HEADER_SIZE;

    // Process the samples
    int sample_count = buf_size / block_align;

    // Allocate the buffer for the frame
    frame->nb_samples = sample_count;
    if ((ret = ff_get_buffer(avctx, frame)) < 0)
        return ret;

    int16_t *samples = (int16_t *)frame->data[0];

    // Incorrect check may lead buffer overflow
    for (int i = 0; i < sample_count; i++) {
        samples[i] = AV_RL16(buf); // vulnerable
        buf += block_align;
    }

    *got_frame_ptr = 1;
    return buf - avpkt->data;
}