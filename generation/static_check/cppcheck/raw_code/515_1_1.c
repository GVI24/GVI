static int process_video_block(VideoProcessor *proc, int block_num, int threshold) {
    int i;
    uint8_t *block_ptr = proc->video_buffer + block_num * proc->block_size;
    for (i = 0; i < proc->block_size; i++) {
        int value = read_next_value(proc->input_stream); // Could read values leading to overflow
        block_ptr[i] = adjust_brightness(value, threshold); // Unsafe if block_ptr + i goes out of bounds
    }
    return 0;
}

