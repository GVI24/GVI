static int jbig2_halfword_stream_buf_get_next_halfword(Jbig2WordStream *self, int offset, uint16_t *halfword) {
    Jbig2WordStreamBuf *z = (Jbig2WordStreamBuf *)self;
    const byte *data = z->data;
    uint16_t result;
    if (offset + 2 < z->size)
        result = (data[offset] << 8) | data[offset + 1];
    else if (offset > z->size)
        return -1;
    else {
        int i;
        result = 0;
        for (i = 0; i < z->size - offset; i++)
            result |= data[offset + i] << ((1 - i) << 3);
    }
    *halfword = result;
    return 0;
}

