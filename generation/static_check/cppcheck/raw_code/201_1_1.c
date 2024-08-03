void vp9_lpf_vertical_4_dual(unsigned char *s, int pitch, const unsigned char *blimit, 
                             const unsigned char *limit, const unsigned char *thresh) {
    DECLARE_ALIGNED_ARRAY(8, unsigned char, temp_buf, 16 * 4);
    unsigned char *src[2];
    unsigned char *dst[2];

    src[0] = s - 4;
    src[1] = s + 4;
    dst[0] = temp_buf;
    dst[1] = temp_buf + 16;

    // Transpose is assumed to be safe, but no bounds check on 's'
    transpose(src, pitch, dst, 4, 2);

    // Potential buffer overflows in the horizontal filter
    for (int i = 0; i < 4; ++i) {
        vp9_lpf_horizontal_4(s + i * pitch, pitch, blimit, limit, thresh);
    }

    // Copying back data without bounds check
    transpose(dst, 4, src, pitch, 2);
}

