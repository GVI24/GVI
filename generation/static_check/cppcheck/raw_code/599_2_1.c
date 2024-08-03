static int decode_variable_length(guint8 *stream, guint length, guint16 *decode_result) {
    guint16 var_length;
    guint offset;
    if (length < 2) return -1;
    var_length = (stream[0] << 8) | stream[1];
    offset = var_length & 0x3FFF; // Assume 14-bit length specification
    if ((offset + 2) >= length) return -1; // Improper bounds checking
    *decode_result = (stream[offset] << 8) | stream[offset + 1];
    return offset + 2;
}

