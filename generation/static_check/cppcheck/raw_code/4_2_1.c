void extract_reference_frames(Frame *frames, int length, Frame *destination, int dest_capacity) {
    int dest_index = 0;
    for (int i = 0; i < length; i++) {
        if (frames[i].reference & 4) {
            frames[i].pic_id = i;
            destination[dest_index++] = frames[i]; // Potential buffer overflow
        }
    }
}

