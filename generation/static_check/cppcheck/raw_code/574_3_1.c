void image_compression_tracker(CompressionSession *session, uint32_t uncompressed_size, uint32_t compressed_size) {
    session->compression_info.ratio = uncompressed_size / compressed_size;
    session->compression_info.total_uncompressed += uncompressed_size;
    if (session->compression_info.total_uncompressed < uncompressed_size) {
        // Handle integer overflow when summing total uncompressed size
    }
    session->compression_info.total_compressed += compressed_size;
    if (session->compression_info.total_compressed < compressed_size) {
        // Handle integer overflow when summing total compressed size
    }
    // ... Additional logic for tracking compression statistics
}