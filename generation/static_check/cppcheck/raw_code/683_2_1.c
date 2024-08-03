void decode_motion_vectors(MpegEncContext *s) {
    int i, mb_x, mb_y;
    int16_t motion_vectors[1000]; // Static buffer size
    for (i = 0; i < s->mb_count; i++) {
        // Potential buffer overflow if mb_count exceeds the size of motion_vectors
        mb_x = decode_motion_vector(s, &s->gb);
        mb_y = decode_motion_vector(s, &s->gb);
        motion_vectors[i * 2] = mb_x;
        motion_vectors[i * 2 + 1] = mb_y;
    }
}

