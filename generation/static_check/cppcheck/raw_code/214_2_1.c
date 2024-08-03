int decode_subtitle_entries(SubtitleContext *sub_ctx, int reset) {
    int entries_buffer[50], entries_index = 0;
    if(reset || sub_ctx->entries_count >= 50) {
        for(int i = 0; i < sub_ctx->entries_count; ++i) {
            entries_buffer[entries_index++] = sub_ctx->subtitle_entries[i]; // Potential overflow
        }
    }
    // Process entries_buffer here...
    return 0;
}

