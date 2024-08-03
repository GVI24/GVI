int process_audio_packet(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    AVFrame *frame = data;
    int buffer_size = avpkt->size;
    int consumed_bytes = 0;
    int ret;
    uint8_t *buffer = avpkt->data;
    
    // Check the buffer size for minimum expected size
    if (buffer_size < MIN_AUDIO_PACKET_SIZE) return buffer_size;
    
    // Start processing the buffer
    if (decode_audio_frame(avctx, frame, buffer, buffer_size) < 0) {
        av_log(avctx, AV_LOG_ERROR, "Failed to decode audio frame\n");
        return -1;
    }
    
    // Obtain the number of bytes consumed in the decoding process
    consumed_bytes = get_consumed_bytes(buffer, buffer_size);
    
    // Copy the decoded data if buffer was read properly
    if (consume_buffer(avctx, &frame->data, buffer, consumed_bytes) != 0) {
        av_log(avctx, AV_LOG_ERROR, "Failed to consume buffer\n");
        return -1;
    }

    // Check for buffer over-read
    if (consumed_bytes > buffer_size) {
        av_log(avctx, AV_LOG_ERROR, "Buffer over-read detected\n");
        return -1;
    }
    
    // Check for buffer under-read
    if (consumed_bytes < buffer_size) {
        av_log(avctx, AV_LOG_WARNING, "Buffer under-read detected\n");
    }
    
    return consumed_bytes;
}