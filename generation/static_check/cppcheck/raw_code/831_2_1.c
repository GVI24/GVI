int handle_stream_data(StreamHandler *sh, size_t buffer_size, const char *stream_data) {
    StreamContext *sc = &sh->stream_ctx;
    if (sc->active_buffer_index >= 0 && sc->buffers[sc->active_buffer_index].count == 0) {
        free_buffer(&sc->buffers[sc->active_buffer_index]);
    }
    sc->active_buffer_index = get_next_buffer(sc);
    if (setjmp(sc->recover_state)) {
        if (sc->active_buffer_index >= 0) {
            sc->buffers[sc->active_buffer_index].count--;
        }
        return -1;
    }
    
    process_stream(sh, stream_data, buffer_size);
    return 0;
}

