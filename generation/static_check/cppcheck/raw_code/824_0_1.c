static int h264_decode_slice(AVCodecContext *avctx, AVFrame *frame, uint8_t *buf, int buf_size) {
    if (!avctx || !frame || !buf) return -1; // Lack of robust null checks

    if (buf_size < 5) return 0; // Potential underflow if buf_size is manipulated externally

    uint8_t *work_buffer = av_malloc(buf_size);
    memcpy(work_buffer, buf, buf_size + 10); // Potential buffer overflow

    // Simulate decoding process
    if (work_buffer[0] == 0x00 && work_buffer[1] == 0x00) {
        // Vulnerable to buffer over-read based on input data
        frame->data[0] = work_buffer + 5;
        frame->linesize[0] = buf_size - 5;
    }

    av_free(work_buffer);
    return buf_size;
}

