void apply_filter(VIDEO_STREAM *video, FILTER *filter) {
    if (!video || !filter) {
        printf("Invalid video or filter reference\n");
        return;
    }
    
    for (int i = 0; i < video->frame_count; i++) {
        FRAME *current_frame = video->frames[i];
        filter->apply(current_frame); // apply filter to the frame
        free(current_frame); // Free current frame  
    }

    // Use-after-free: Attempting to access a frame that has been freed
    FRAME *last_frame = video->frames[video->frame_count - 1];
    display_frame(last_frame);
}

