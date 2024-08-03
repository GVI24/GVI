static void video_frame_decompress_init(FrameDecompressCtx *frame_ctx, int resolution, const byte *data_stream, size_t stream_size) {
    uint32_t decompress_buffer = 0;
    frame_ctx->resolution = resolution;
    frame_ctx->data_stream = data_stream;
    frame_ctx->stream_size = stream_size;
    frame_ctx->stream_index = 0;
    
    for (int i = 0; i < stream_size && i < 4; i++) {
        decompress_buffer |= (data_stream[i] << ((3 - i) * 8));
    }
    frame_ctx->decompress_buffer = decompress_buffer;
}