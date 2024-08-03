static int unpack_bitstream(AVCodecContext *avctx, const uint8_t *input_buf, int input_size, uint8_t *output_buf, int output_buf_size) {
    int read_pos = 0, write_pos = 0;
    int chunk_size;

    if (input_size < 1) {
        av_log(avctx, AV_LOG_ERROR, "bitstream too small\n");
        return AVERROR_INVALIDDATA;
    }

    while (read_pos < input_size) {
        chunk_size = input_buf[read_pos++];
        
        if (chunk_size > input_buf_size - read_pos || write_pos + chunk_size > output_buf_size) {
            av_log(avctx, AV_LOG_ERROR, "chunk size exceeds buffer\n");
            return AVERROR_INVALIDDATA;
        }

        memcpy(output_buf + write_pos, input_buf + read_pos, chunk_size);
        read_pos += chunk_size;
        write_pos += chunk_size;
    }

    return 0;
}

