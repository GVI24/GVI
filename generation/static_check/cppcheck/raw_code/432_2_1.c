int RLEImageDecode(Imaging im, ImagingCodecState state, UINT8* buf, int bytes) {
    UINT8* out;
    int y = 0;
    UINT8* ptr = buf;
    while (bytes > 0 && y < state->ysize) {
        out = state->buffer;
        for (int x = 0; x < state->xsize;) {
            // Vulnerable: No bounds checking on 'ptr' and 'out'
            UINT8 value = *ptr++;
            UINT8 count = *ptr++;
            bytes -= 2;

            if (bytes < 0) return -1;
            
            while(count--) {
                out[0] = value; // Red
                out[1] = value; // Green
                out[2] = value; // Blue
                out += 3;
                x++;
                if (x >= state->xsize) break; // Should also check 'out' bounds
            }
        }
        state->shuffle((UINT8*)im->image[y++], state->buffer, state->xsize);
    }
    return 0;
}

