static void rgb_to_grayscale (Image *img, int row) {
    int i;
    int offset[AV_NUM_DATA_POINTERS];
    int width = img->width;

    if (img->convert_grayscale == NULL) return;

    int height = row - img->last_processed_row;
    img->last_processed_row = row;
    row -= height;

    offset[0] = img->frame.linesize[0] * row;

    for (i = 1; i < AV_NUM_DATA_POINTERS; i++) {
        offset[i] = 0;
    }

    // Potential for buffer overflow if row indices are out of bounds
    img->convert_grayscale(img->frame.data[0] + offset[0], width, height);
}

