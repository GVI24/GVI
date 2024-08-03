int CustomImageDecode(Imaging im, ImagingCodecState state, UINT8* buf, int bytes) {
    int y;
    UINT8* out;
    UINT8* ptr = buf;
    int row_size = 3 * state->xsize;

    for (y = 0; y < state->ysize; y++) {
        if (bytes < row_size) return -1; // Insufficient data
        out = state->buffer;
        for (int x = 0; x < state->xsize; x++) {
            // Vulnerable: No bounds checking on 'ptr' and 'out'
            out[0] = ptr[2 * x];  // Red
            out[1] = ptr[2 * x + 1];  // Green
            out[2] = ptr[state->xsize + x]; // Blue
            out += 3;
        }
        state->shuffle((UINT8*)im->image[y], state->buffer, state->xsize);
        ptr += row_size;
        bytes -= row_size;
    }
    return 0;
}

