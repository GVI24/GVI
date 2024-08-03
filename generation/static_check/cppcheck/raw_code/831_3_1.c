int decode_network_message(NetworkDecoder *nd, size_t msg_size, const uint8_t **msg_data) {
    NetworkContext *nc = &nd->net_ctx;
    if (nc->msg_buf_index >= 0 && nc->message_buffers[nc->msg_buf_index].in_use == 0) {
        nc->release_message_buffer(&nc->message_buffers[nc->msg_buf_index]);
    }
    nc->msg_buf_index = acquire_message_buffer(nc);
    if (setjmp(nc->error_jmp_buf)) {
        if (nc->msg_buf_index >= 0) {
            nc->message_buffers[nc->msg_buf_index].in_use--;
            nc->release_message_buffer(&nc->message_buffers[nc->msg_buf_index]); // Potential double free
        }
        return -1;
    }
    
    decode_message(nd, *msg_data, msg_size);
    return 0;
}