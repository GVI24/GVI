static int jbig2_endian_stream_buf_get_next_halfword(Jbig2WordStream *self, int offset, uint16_t *halfword, int big_endian) {
    Jbig2WordStreamBuf *z = (Jbig2WordStreamBuf *)self;
    const byte *data = z->data;
    uint16_t result;
    if ((offset + 2 <= z->size) && big_endian)
        result = (data[offset] << 8) | data[offset + 1];
    else if ((offset + 2 <= z->size) && !big_endian)
        result = data[offset] | (data[offset + 1] << 8);
    else if (offset >= z->size)
        return -1;
    else {
        int i;
        result = 0;
        for (i = 0; offset + i < z->size && i < 2; i++)
            if (big_endian)
                result |= data[offset + i] << ((1 - i) << 3);
            else
                result |= data[offset + i] << (i << 3);
    }
    *halfword = result;
    return 0;
}