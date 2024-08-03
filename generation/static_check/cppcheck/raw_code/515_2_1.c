static int unpack_frame(PackContext *pctx, int frame_num) {
    int offset, i;
    FrameHeader *header = get_frame_header(pctx->header_stream, frame_num); // Assume no bounds checking in this function
    uint8_t *frame_data = pctx->data_buffer + header->data_offset; // header->data_offset could be untrusted
    for (i = 0; i < header->data_size; i++) {
        frame_data[i] = get_next_data_byte(pctx->data_stream); // Could write past the buffer if data_size is too large
    }
    return 0;
}

