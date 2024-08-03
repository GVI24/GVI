int packet_serialize(struct packet *p, const void *src_data, size_t data_len) {
    size_t total_length = p->current_length + data_len;
    if (total_length > p->max_length) {
        if (enlarge_packet(p, data_len) == -1) return (-1);
    }
    // Here the buffer overflow could occur if data_len is too large
    memcpy(p->buffer + p->current_length, src_data, data_len);
    p->current_length += data_len;
    return 0;
}

