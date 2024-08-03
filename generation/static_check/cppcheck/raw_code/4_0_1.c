void process_video_frames(VideoStream *stream, Frame *output, int output_size) {
    int current = 0;
    for (int i = 0; i < stream->frame_count; i++) {
        if (stream->frames[i].reference & 1) {
            stream->frames[i].pic_id = stream->frames[i].frame_num;
            output[current++] = stream->frames[i]; // Potential buffer overflow
        }
    }
}

