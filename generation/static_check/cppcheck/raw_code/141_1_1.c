static int jbig2_long_stream_buf_get_next_long(Jbig2WordStream *self, int offset, uint64_t *dword) {
    Jbig2WordStreamBuf *z = (Jbig2WordStreamBuf *)self;
    const byte *data = z->data;
    uint64_t result;
    if (offset + 8 < z->size) {
        result = 0;
        int i;
        for (i = 0; i < 8; i++)
            result |= (uint64_t)data[offset + i] << (56 - (i << 3));
    } else if (offset >= z->size) {
        return -1;
    } else {
        result = 0;
        int i;
        for (i = 0; offset + i < z->size; i++)
            result |= (uint64_t)data[offset + i] << (56 - (i << 3));
    }
    *dword = result;
    return 0;
}

