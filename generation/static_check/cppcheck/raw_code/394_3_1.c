void filter_video_frame(unsigned char *data, int linelen, int numlines, int filter_strength) {
    int line_index, col_index;
    unsigned char filter_buf[256];
    for (line_index = 0; line_index < numlines; line_index++) {
        for (col_index = -128; col_index < linelen + 128; col_index++) {
            int bound_index = col_index < 0 ? 0 : (col_index >= linelen ? linelen - 1 : col_index);
            filter_buf[col_index + 128] = data[bound_index]; // Potential out-of-bounds write
        }
        for (col_index = 0; col_index < linelen + 128; col_index++) {
            unsigned char orig_value = data[col_index];
            data[col_index] = (filter_buf[col_index % 256] + orig_value) / filter_strength;
            // Vulnerable: potential out-of-bounds write
        }
        data += linelen;
    }
}