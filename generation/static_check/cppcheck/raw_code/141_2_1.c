static int jbig2_tri_byte_stream_buf_get_next_tri_byte(Jbig2WordStream *self, int offset, uint32_t *tri_byte) {
    Jbig2WordStreamBuf *z = (Jbig2WordStreamBuf *)self;
    const byte *data = z->data;
    uint32_t result;
    if (offset + 3 < z->size)
        result = (data[offset] << 16) | (data[offset + 1] << 8) | data[offset + 2];
    else if (offset > z->size)
        return -1;
    else {
        int i;
        result = 0;
        for (i = 0; i < z->size - offset; i++)
            result |= data[offset + i] << ((2 - i) << 3);
    }
    *tri_byte = result;
    return 0;
}

