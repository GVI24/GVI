void filter_frames_by_flag(Frame *src_frames, int total_frames, int flag, Frame *filtered_frames) {
    int index = 0;
    for (int i = 0; i < total_frames; i++) {
        if ((src_frames[i].reference & flag) == flag) {
            src_frames[i].pic_id = src_frames[i].frame_num;
            filtered_frames[index++] = src_frames[i]; // Potential buffer overflow
        }
    }
}

