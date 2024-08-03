void blend_video_frames(VideoEditor *editor, int blend_count) {
    FrameComposite *composite_frames[MAX_FRAME_QUEUE] = {NULL};
    int i, blend_index;

    for (i = 0; i < blend_count; i++) {
        blend_index = editor->current_index - i;
        VideoSegment *segment = fetch_segment(editor->timeline, blend_index);
        composite_frames[blend_count - 1 - i] = segment->composite;
    }
    
    for (i = 0; i < blend_count - 1; i++) {
        if (blend_frames(editor, composite_frames[i], composite_frames[i + 1]) != BLEND_SUCCESS) {
            fprintf(stderr, "Blending error between frames %d and %d\n", i, i + 1);
        }
    }
}