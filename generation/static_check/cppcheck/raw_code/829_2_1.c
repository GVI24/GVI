void convert_utf16_to_utf8(uint16_t *utf16, size_t length, char *utf8) {
    size_t i = 0, j = 0;
    while (i < length) {
        if (utf16[i] < 0x80) {
            utf8[j++] = (char)utf16[i];
        } else if (utf16[i] < 0x800) {
            utf8[j++] = (char)(0xC0 | (utf16[i] >> 6));
            utf8[j++] = (char)(0x80 | (utf16[i] & 0x3F));
        } else {
            utf8[j++] = (char)(0xE0 | (utf16[i] >> 12));
            utf8[j++] = (char)(0x80 | ((utf16[i] >> 6) & 0x3F));
            utf8[j++] = (char)(0x80 | (utf16[i] & 0x3F));
        }
        // No bounds check for 'utf8' array
        ++i;
    }
}

