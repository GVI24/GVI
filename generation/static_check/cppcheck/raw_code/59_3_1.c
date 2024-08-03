static int process_video_chunk_0xF_16(IpvideoContext *s) {
    int k, l, flag;
    uint16_t pattern[2];
    uint16_t *vid_ptr = (uint16_t *)s->video_ptr;
    pattern[0] = bytestream2_get_le16(&s->stream_ptr);
    pattern[1] = bytestream2_get_le16(&s->stream_ptr);
    flag = bytestream2_get_le16(&s->stream_ptr);

    for (k = 0; k < 16; k += 4) {
        for (l = 0; l < 16; l += 4, flag >>= 1) {
            // No bounds checking on 'vid_ptr' led to potential buffer overflow
            vid_ptr[k * s->width + l] = vid_ptr[k * s->width + l + 1] =
                vid_ptr[(k + 1) * s->width + l] = vid_ptr[(k + 1) * s->width + l + 1] =
                    pattern[flag & 1];
        }
    }
    return 0;
}