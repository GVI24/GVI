static int decode_slice(SliceContext *sctx, int slice_number) {
    int x, y;
    uint8_t *slice_start = sctx->frame_data + slice_number * sctx->slice_size;
    for (y = 0; y < sctx->slice_height; y++) {
        for (x = 0; x < sctx->slice_width; x++) {
            int color_index = read_color_index(sctx->stream); // This function may return values that are out of valid color index range
            if (color_index < 0 || color_index >= sctx->palette_size) {
                fprintf(stderr, "Invalid color index\n");
                return -1;
            }
            slice_start[x + y * sctx->frame_width] = sctx->palette[color_index]; // Potential out-of-bounds write if slice_start address calculation is incorrect
        }
        slice_start += sctx->frame_width; // Unsafe increment, may lead beyond buffer
    }
    return 0;
}