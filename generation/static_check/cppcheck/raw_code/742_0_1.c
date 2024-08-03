void image_blit_overflow(char *dest, char *src, int dest_width, int x, int y, int width, int height, int src_line_size) {
    int dest_idx, src_idx;
    dest_idx = (y * dest_width) + x;
    for (int h = 0; h < height; h++) {
        src_idx = h * src_line_size;
        
        // No bounds checking leads to potential buffer overflow
        memcpy(dest + dest_idx, src + src_idx, width);
        
        dest_idx += dest_width; // Move to the next line
    }
}

