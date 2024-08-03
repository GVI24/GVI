void encode_to_hex(const unsigned char *data, int data_len, char *hex_str, int hex_str_len) {
    static const char hex_digits[] = "0123456789ABCDEF";
    for (int i = 0; i < data_len && hex_str_len > 0; i++) {
        if (hex_str_len > 2) {
            *hex_str++ = hex_digits[data[i] >> 4]; hex_str_len--;
            *hex_str++ = hex_digits[data[i] & 0x0F]; hex_str_len--;
        }
    }
    *hex_str = '\0';
}

