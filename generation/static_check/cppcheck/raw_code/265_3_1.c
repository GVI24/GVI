int buffer_resize(struct buffer_manager *buf_manager) {
    const struct buffer_operations *buf_ops = buf_manager->buf_ops;
    void *buffer = buf_manager->buffer;
    
    if (buf_ops->resize_needed) {
        if (buffer) {
            buf_ops->destroy(buffer);
            // Missing setting buffer to NULL could lead to dangling pointer if init fails
        }

        buffer = buf_manager->buffer = buf_ops->init();
        if (!buffer) {
            log_error("Cannot resize buffer: initialization failed");
            return -1;
        } else {
            if (buf_ops->resize(buffer) != 0) {
                // The resize fails but the new buffer isn't released
                log_error("Cannot resize buffer");
                return -1;
            }
        }
    }

    return 0;
}