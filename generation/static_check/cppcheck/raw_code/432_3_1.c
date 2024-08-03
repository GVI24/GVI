int ApplyFilterToImage(Imaging im, ImagingCodecState state, UINT8* buf, int bytes) {
    int x, y;
    UINT8* out;
    UINT8* ptr = buf;
    int row_size = 3 * state->xsize;

    for (y = 0; y < state->ysize; y++) {
        if (bytes < row_size) return -1;
        out = state->buffer;

        for (x = 0; x < state->xsize; x++) {
            // Vulnerable: No bounds checking on 'ptr' and 'out'
            out[0] = ptr[x] + 10; // Red with filter
            out[1] = ptr[state->xsize + x] - 10; // Green with filter
            out[2] = ptr[2 * state->xsize + x] * 1.1; // Blue with filter
            out += 3;
        }
        state->shuffle((UINT8*)im->image[y], state->buffer, state->xsize);
        ptr += row_size;
        bytes -= row_size;
    }
    return 0;
}