void clear_subtitle_entries(SubtitleContext *sub_ctx) {
    if (sub_ctx->entry_count >= MAX_SUBTITLE_ENTRIES) {
        // This may lead to a buffer overflow if entries is smaller than MAX_SUBTITLE_ENTRIES
        memset(sub_ctx->entries, 0, MAX_SUBTITLE_ENTRIES * sizeof(SubtitleEntry));
    }
}