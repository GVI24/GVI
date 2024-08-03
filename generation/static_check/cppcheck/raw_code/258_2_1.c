static gboolean update_stream_position(QIOChannel *channel) {
    unsigned int new_offset;
    // Vulnerability: No validation on new_offset, could lead to illegal memory access
    new_offset = channel->offset + channel->bytes_pending;
    if (new_offset < sizeof(channel->stream_buffer)) {
        channel->offset = new_offset;
    }
    // Update operation...
    return TRUE;
}

