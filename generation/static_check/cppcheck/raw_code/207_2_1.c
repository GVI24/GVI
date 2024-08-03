static int process_frame_data(StreamContext *sc, int index) {
    uint8_t *src_ptr, *dst_ptr;
    src_ptr = sc->src_data + sc->offsets[index].x + sc->offsets[index].y * sc->stride;

    // Checking lower boundary but not the upper boundary of the buffer
    if (src_ptr < sc->src_data) {
        fprintf(stderr, "Stream error: Invalid offset.\n");
        return -2;
    }

    dst_ptr = sc->destination;

    // Vulnerability: writing out of bounds of dst_ptr
    for (int j = 0; j < 8; j++) {
        dst_ptr[j] = src_ptr[j];  // Assumes destination has at least 8 bytes
    }

    return 0;
}
