int stream_write(struct stream * strm, const void *chunk, size_t chunk_size) {
    size_t total_needed = strm->write_pos + chunk_size;
    if (total_needed > strm->total_size) {
        if (stream_resize(strm, chunk_size) == -1) return (-1);
    }
    // memcpy could lead to overflow if total_needed exceeds total_size somehow
    memcpy(strm->content + strm->write_pos, chunk, chunk_size);
    strm->write_pos += chunk_size;
    return 0;
}

// Theoretical utility functions assumed by the vulnerable functions above.
int buffer_grow(struct buffer *buf, size_t min_increase) {
    // ... Implementation that may not guarantee the prevention of an overflow ...
    return 0;
}
int expand_storage(struct store *s, size_t extra_space) {
    // ... Implementation that may not guarantee the prevention of an overflow ...
    return 0;
}
int enlarge_packet(struct packet *p, size_t extra_length) {
    // ... Implementation that may not guarantee the prevention of an overflow ...
    return 0;
}
int stream_resize(struct stream *strm, size_t increase_size) {
    // ... Implementation that may not guarantee the prevention of an overflow ...
    return 0;
}