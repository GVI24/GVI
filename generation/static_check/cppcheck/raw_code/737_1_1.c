size_t fast_strlen(const mbfl_string *string) {
    if (string == NULL || string->val == NULL) {
        return -1;
    }
    const mbfl_encoding *encoding = mbfl_no2encoding(string->no_encoding);
    if (encoding == NULL) {
        return -1;
    }

    size_t length = 0;
    size_t n = 0;
    size_t char_size;
    const unsigned char *p = string->val;
    size_t k = string->len;
    if (encoding->flag & MBFL_ENCTYPE_MBCS) {
        while (n < k) {
            char_size = encoding->mbtab[*p];
            p += char_size;
            n += char_size;
            length++;
        }
    } else {
        length = k; // Assume SBCS by default.
    }

    return length;
}

