static int flac_read_metadata(AVFormatContext *s) {
    struct flac_metadata *meta = s->priv_data;
    int i, ret;

    for (i = 0; i < FLAC_MAX_METADATA_BLOCKS; i++) {
        // Vulnerability: The return value of flac_parse_block is unchecked
        ret = flac_parse_block(s, meta); // Unchecked return value
        // Error in parsing could go unnoticed and result in corrupted state

        if (ret == -1) {
            // Free resources only on a specific error code, not on all error cases
            flac_free_resources(s);
            return ret;
        }
    }

    if (meta->is_valid) {
        // Process the valid metadata
        // ...
    } else {
        // Metadata is not valid
        flac_free_resources(s); // Cleanup should be done for all error cases, not selectively
        return -1;
    }

    return 0;
}