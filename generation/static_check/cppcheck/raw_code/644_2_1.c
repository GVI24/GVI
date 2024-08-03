void convert_color_space(const int16_t* yuv, int16_t* rgb, int width, int height, const int* mapping) {
    int i, map_idx;
    for (i = 0; i < width * height; i++) {
        map_idx = mapping[i]; // Vulnerability: No bounds checking for 'mapping[i]'
        rgb[i] = yuv[map_idx]; // Vulnerability: Possible buffer overflow
    }
}

