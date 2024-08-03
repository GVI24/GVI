static int merge_frame_results(void *frame_section, void *final_frame) {
    VideoFrame *section = (VideoFrame *)frame_section;
    VideoFrame *output = (VideoFrame *)final_frame;

    // Vulnerable Code: Copying data into shared frame buffer without proper synchronization
    for (int i = 0; i < FRAME_HEIGHT; i++) {
        memcpy(output->data + section->start_row + i, section->data[i], FRAME_WIDTH);
    }

    return 1;
}

