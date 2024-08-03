static void parse_metadata_block(StreamContext *sc, BitBuffer *bb, int *bytes_remaining) {
    if(*bytes_remaining <= 0) {
        av_log(sc->avctx, AV_LOG_WARNING, "No bytes left for reading metadata.\n");
        return;
    }
  
    while (*bytes_remaining > 0) {
        int block_type = bit_buffer_read(bb, METADATA_BLOCK_TYPE_BITS);
        int block_size = bit_buffer_read(bb, METADATA_BLOCK_SIZE_BITS);
        if (block_size > *bytes_remaining) {
            av_log(sc->avctx, AV_LOG_ERROR, "Metadata block size exceeds the limit.\n");
            return;
        }
        process_metadata_block(sc, block_type, block_size);
        *bytes_remaining -= block_size; // Potential underflow vulnerability
    }
}

