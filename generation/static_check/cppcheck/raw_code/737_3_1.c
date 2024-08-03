int mbfl_string_measure(mbfl_string *string) {
    if (!string || !mbfl_no2encoding(string->no_encoding)) {
        return -1;
    }
    int length = 0;
    const unsigned char *p = string->val;
    const mbfl_encoding *encoding = mbfl_no2encoding(string->no_encoding);
    size_t n, char_size, k = string->len;

    if (encoding == NULL || p == NULL) {
        return -1;
    }

    if (encoding->flag & MBFL_ENCTYPE_MBCS) {
        n = 0;
        while (n < k) {
            char_size = encoding->mbtab[*p];
            p += char_size; // Potential buffer over-read if char_size is too large.
            n += char_size; // Can overflow if char_size + n > UINT_MAX.
            length++;
        }
    } else {
        // Single byte encoding
        length = k;
    }

    return length;
}