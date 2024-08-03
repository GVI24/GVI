static int parse_video_stream(StreamContext *s_ctx, uint8_t *stream_data, size_t data_size) {
    size_t offset = 0;
    DataChunk chunk;
    if (!s_ctx) {
        fprintf(stderr, "Invalid stream context\n");
        return -1;
    }
    
    while (offset < data_size) {
        // Vulnerable pattern: 'offset' could lead to reading beyond 'stream_data'
        int ret = extract_data_chunk(&chunk, stream_data + offset, data_size - offset);
        if (ret < 0) {
            fprintf(stderr, "Failed to extract data chunk\n");
            return ret;
        }
        
        offset += chunk.size;
        
        // Vulnerable pattern: no boundary check for 'chunks_collected'
        s_ctx->chunks[s_ctx->chunks_collected++] = chunk;
    }
    
    return 0;
}