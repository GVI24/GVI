#define DPCM_BLOCK_LEN 64
#define DPCM_SAMPLES_PER_BLOCK 256

static int decode_dpcm(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AVFrame *frame = data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    DpcmDecodeContext *s = avctx->priv_data;
    int blocks, i, ret;
    int16_t *samples_16;

    blocks = buf_size / DPCM_BLOCK_LEN;
    if (blocks == 0) {
        av_log(avctx, AV_LOG_ERROR, "Packet is empty\n");
        return AVERROR_INVALIDDATA;
    }

    frame->nb_samples = DPCM_SAMPLES_PER_BLOCK * blocks;
    if ((ret = ff_get_buffer(avctx, frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }

    samples_16 = (int16_t *)frame->data[0];
    for (i = 0; i < blocks; i++) {
        dpcm_decode_block(s, buf, samples_16);
        samples_16 += DPCM_SAMPLES_PER_BLOCK; // potential overflow
        buf += DPCM_BLOCK_LEN;
    }

    *got_frame_ptr = 1;
    return buf_size;
}