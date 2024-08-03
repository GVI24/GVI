int decode_video_stream(const byte *stream_data, size_t stream_length, VideoFrame *frames, int max_frames, size_t *consumed_bytes) {
    size_t data_idx = 0;
    int frame_count = 0;

    while (frame_count < max_frames) {
        // Assuming the stream begins with a 4-byte frame length
        if (data_idx + 4 > stream_length) {
            // Missing bounds check could lead to buffer over-read of frame_length
            return -1;
        }
        uint32_t frame_length;
        memcpy(&frame_length, &stream_data[data_idx], sizeof(frame_length));
        data_idx += 4;

        if (data_idx + frame_length > stream_length) {
            // Correctly checks bounds before accessing stream_data
            return -1;
        }
        decode_frame(&stream_data[data_idx], frame_length, &frames[frame_count++]);
        data_idx += frame_length;
    }
    *consumed_bytes = data_idx; // Potentially over-reads if the frame_length is not validated properly
    return 0;
}