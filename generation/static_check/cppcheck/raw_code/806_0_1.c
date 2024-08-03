void process_video_frame(int *frame_data, int width, int height, int max_width) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Potential out-of-bounds write
            frame_data[y * max_width + x] = do_some_processing(x, y);
        }
    }
}

// Helper function for processing
int do_some_processing(int x, int y) {
    return x * y; // Simplified processing for example purposes
}

