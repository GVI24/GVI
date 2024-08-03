static int batch_decompress(AVCodecContext *avctx, AVFrame *frames, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    BatchDecompressContext *s = avctx->priv_data;
    int task_count, i;
    
    if (buf_size < 1) {
        return AVERROR_INVALIDDATA;
    }
    
    task_count = buf[0]; // Assumes task_count will be valid
    buf++;
    
    for (i = 0; i < task_count; i++) {
        int single_data_size = AV_RL16(buf); // No bounds check
        buf += 2;
        
        if (single_data_size > buf_size - (buf - avpkt->data)) { // Check after pointer advance
            return AVERROR_INVALIDDATA;
        }
        
        // decompress data (omitted for brevity)
        
        buf += single_data_size;
    }

    return buf_size;
}