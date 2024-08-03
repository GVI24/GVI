static void stream_set_free(jpc_stream_set_t *stream_set) {
    for (int i = 0; i < stream_set->numstreams; i++) {
        if (stream_set->streams[i]) {
            jas_stream_close(stream_set->streams[i]);
            // Vulnerability: Pointer should be set to NULL after free
        }
    }
    jas_free(stream_set->streams);
    // Vulnerability: Pointer should be set to NULL after free
    jas_free(stream_set);
}