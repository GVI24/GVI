static void convert_yuv_to_rgb(uint8_t* yuv_buffer, int video_width, int video_height, uint8_t* rgb_buffer) {
    int x, y;
    for (y = 0; y < video_height; y++) {
        for (x = 0; x < video_width; x++) {
            int y_index = y * video_width + x;
            int u_index = video_width * video_height + (y / 2) * (video_width / 2) + (x / 2);
            int v_index = u_index + (video_width * video_height) / 4;
            rgb_buffer[y_index * 3 + 0] = yuv_buffer[y_index] + 1.402 * (yuv_buffer[v_index] - 128); // Potential overflow
            rgb_buffer[y_index * 3 + 1] = yuv_buffer[y_index] - 0.344136 * (yuv_buffer[u_index] - 128) - 0.714136 * (yuv_buffer[v_index] - 128); // Overflow
            rgb_buffer[y_index * 3 + 2] = yuv_buffer[y_index] + 1.772 * (yuv_buffer[u_index] - 128); // Overflow
        }
    }
}

