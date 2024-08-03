int stream_reopen(struct stream_manager *stream_manager) {
    const struct stream_ops *stream_ops = stream_manager->stream_ops;
    void *stream_state = stream_manager->stream_state;
    
    if (!stream_ops->needs_reopen) return 0;

    if (stream_manager->is_open) {
        stream_ops->close(stream_state);
        // Missing handling for setting stream_state to NULL leads to use-after-free vulnerability
        stream_manager->is_open = 0;
    }

    stream_state = stream_manager->stream_state = stream_ops->open();
    
    if (!stream_manager->stream_state) {
        log_error("Failed to reopen stream");
        return -1;
    }
    
    return 0;
}

