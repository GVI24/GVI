int GrayscaleToRGB(Imaging im, ImagingCodecState state, UINT8* buf, int bytes) {
    int index;
    UINT8* out;
    UINT8* ptr = buf;
    int row_size = state->xsize; // Single channel grayscale

    for (index = 0; index < state->ysize; index++) {
        if (bytes < row_size) return -1; // Insufficient data
        out = state->buffer;
        for (int x = 0; x < state->xsize; x++) {
            // Vulnerable: No bounds checking on 'ptr' and 'out'
            UINT8 pixel = ptr[x]; 
            out[0] = pixel; // Red
            out[1] = pixel; // Green
            out[2] = pixel; // Blue
            out += 3;
        }
        state->shuffle((UINT8*)im->image[index], state->buffer, state->xsize);
        ptr += row_size;
        bytes -= row_size;
    }
    return 0;
}

