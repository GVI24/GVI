static int unsafe_read(z_stream *zs, unsigned char *in_buffer, unsigned char *out_buffer, size_t out_buffer_size) {
    zs->next_in = in_buffer;
    zs->avail_in = strlen((char *)in_buffer); // Dangerous use of strlen without proper input validation
    zs->next_out = out_buffer;
    zs->avail_out = out_buffer_size;

    while (zs->avail_out > 0 && zs->avail_in > 0) {
        if (inflate(zs, Z_NO_FLUSH) != Z_OK) {
            return -1;
        }
    }
    return 0;
}

