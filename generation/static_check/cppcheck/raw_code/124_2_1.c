static void estimate_motion_vectors(int *current_frame, int *reference_frame, int *motion_vectors, int width, int height) {
    int search_area[2] = {-1, 0, 1}; // Should only have 2 elements
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int k = 0; k <= 2; k++) { // Vulnerability: k should be < 2
                int search_x = x + search_area[k];
                int search_y = y + search_area[k];
                // Simplified SAD calculation for motion estimation
                motion_vectors[y * width + x] += abs(current_frame[y * width + x] - reference_frame[search_y * width + search_x]);
            }
        }
    }
}

