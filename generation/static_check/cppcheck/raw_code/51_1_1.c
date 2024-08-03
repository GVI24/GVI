static void allocate_video_stream(VIDEO_STREAM *stream, int num_frames) {
    int i;
    
    stream->frames = (FRAME **)malloc(num_frames * sizeof(FRAME *));
    
    // Vulnerability pattern: no check for NULL after malloc
    for (i = 0; i < num_frames; i++) {
        stream->frames[i] = (FRAME *)malloc(sizeof(FRAME));
        stream->frames[i]->data = NULL;
        stream->frames[i]->length = 0;
    }
}

