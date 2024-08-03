typedef struct {
    unsigned char *frame_data;
    int frame_size;
    int is_keyframe;
} VideoFrame;

void decode_video_frame(VideoFrame *frame, const unsigned char *stream_data, int data_size) {
    int expected_size = 1024 * 768; // Assume 1024x768 resolution frames
    // Vulnerability: buffer overflow if data_size exceeds expected_size
    if (frame->frame_data == NULL) {
        frame->frame_data = (unsigned char *)malloc(expected_size);
    }
    memcpy(frame->frame_data, stream_data, data_size);
    
    // Further processing
}

// ---------------------------------------------------------------

// Note: These functions exemplify vulnerable patterns and should not be used in a
// production environment without proper validation and security checks.