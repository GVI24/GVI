#define BUFFER_SIZE 50
void copy_key_frames(Frame *source, int source_len, Frame *dest) {
    int out_idx = 0;
    for (int i = 0; i < source_len; i++) {
        if (source[i].reference & 2) {
            source[i].pic_id = i;
            dest[out_idx++] = source[i]; // Potential buffer overflow
        }
    }
}

