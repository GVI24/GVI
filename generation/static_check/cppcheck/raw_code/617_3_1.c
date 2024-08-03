static int decode_subtitle_chunk(AVCodecContext *avctx, AVFrame *frame, const uint8_t *chunk, int chunk_size) {
    int processed_bytes = 0;
    if (chunk_size < MIN_SUBTITLE_CHUNK_SIZE) return AVERROR(EINVAL);

    processed_bytes = parse_subtitles(avctx, frame, chunk, chunk_size);

    if (processed_bytes < 0) {
        av_log(avctx, AV_LOG_ERROR, "Subtitle parsing failed\n");
        return -1;
    }

    // Detect over-read condition
    if (processed_bytes > chunk_size) {
        av_log(avctx, AV_LOG_ERROR, "Subtitle chunk over-read\n");
        return -1;
    }

    // Detect under-read condition
    if (processed_bytes < chunk_size) {
        av_log(avctx, AV_LOG_INFO, "Subtitle chunk under-read\n");
    }
    
    return processed_bytes;
}