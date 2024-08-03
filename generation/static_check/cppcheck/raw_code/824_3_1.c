static int mpeg4_decode_picture(AVCodecContext *avctx, AVFrame *frame, AVPacket *avpkt) {
    int buf_size = avpkt->size;
    uint8_t *buf = avpkt->data;

    // Direct use of buffer data with no validation
    int frame_type = buf[0];

    // Allocate a buffer based on size from buf, potential under-allocation
    uint8_t *output_buffer = (uint8_t *)av_malloc(frame_type * sizeof(uint8_t));
    memcpy(output_buffer, buf + 1, buf_size); // buffer overflow if frame_type < buf_size

    // Fake decode simulation
    if (output_buffer[0] == I_FRAME) {
        frame->data[0] = output_buffer + 1; // Use of potentially faulty data
        frame->linesize[0] = buf_size - 1;
    } else {
        av_free(output_buffer); // Missing free in the if case
        return -1;
    }

    return buf_size;
}