void process_frame_edges(unsigned char *frame, int width, int height, int threshold) {
    int row, col, idx;
    unsigned char buffer[32];
    for (row = 0; row < height; row++) {
        int sum = 0;
        for (idx = -16; idx < width + 16; idx++) {
            buffer[idx] = frame[idx < 0 ? 0 : (idx >= width ? width - 1 : idx)];
            sum += buffer[idx];
        }
        for (col = 0; col < width + 16; col++) {
            buffer[col] = (sum + frame[col]) / 2;
            frame[col] = buffer[col % 32]; // Vulnerable: potential out-of-bounds write
        }
        frame += width;
    }
}
