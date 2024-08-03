typedef struct {
    uint8_t *frame_data;
    size_t data_size;
} VideoFrame;

int copy_video_frame(VideoFrame *dest_frame, const VideoFrame *src_frame) {
    if (dest_frame->data_size < src_frame->data_size) {
        // Handle error for insufficient destination size
        return -1;
    }

    // Potential buffer overflow vulnerability
    memcpy(dest_frame->frame_data, src_frame->frame_data, src_frame->data_size + 1024); // Incorrect additional bytes

    return 0;
}