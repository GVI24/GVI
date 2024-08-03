typedef struct {
    uint8_t *data_content;
    int max_entries;
} FileParseContext;

int parse_custom_file_format(FileParseContext *ctx, const uint8_t *file_data, int file_size) {
    int entry_id;
    unsigned int entry_data_size;

    if (file_size < 4) return -1;

    entry_id = bytestream_get_byte(&file_data);
    entry_data_size = bytestream_get_be24(&file_data);
    
    if (entry_data_size + 4 > file_size) return -1;

    if (entry_id >= ctx->max_entries) return -1;  // Risk of overflow if entry_id is unchecked
    
    memcpy(ctx->data_content + entry_id * ctx->max_entries, file_data, entry_data_size);  // Vulnerable to overflow

    return 0;
}