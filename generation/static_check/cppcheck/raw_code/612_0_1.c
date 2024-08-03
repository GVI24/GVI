void estimate_motion(int *motion_vector, int block_size, int *current_frame, int *reference_frame, int width, int height) {
    int mv_x = 0, mv_y = 0;
    int best_score = INT_MAX;
    for (int y = 0; y < height; y += block_size) {
        for (int x = 0; x < width; x += block_size) {
            for (int search_y = -block_size; search_y <= block_size; search_y++) {
                for (int search_x = -block_size; search_x <= block_size; search_x++) {
                    int score = 0;
                    for (int by = 0; by < block_size; by++) {
                        for (int bx = 0; bx < block_size; bx++) {
                            // Vulnerability: Potential out-of-bounds read
                            int ref_val = reference_frame[(y + search_y + by) * width + (x + search_x + bx)];
                            int cur_val = current_frame[(y + by) * width + (x + bx)];
                            score += abs(ref_val - cur_val);
                        }
                    }
                    if (score < best_score) {
                        best_score = score;
                        mv_x = search_x;
                        mv_y = search_y;
                    }
                }
            }
            motion_vector[(y / block_size) * (width / block_size) + (x / block_size)] = (mv_y << 16) | (mv_x & 0xFFFF);
        }
    }
}

