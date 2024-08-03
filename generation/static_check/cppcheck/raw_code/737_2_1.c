int mbfl_char_count(mbfl_string *string) {
    if (string == NULL || string->val == NULL) {
        return -1;
    }
    int count = 0;
    const unsigned char *p;
    size_t n, char_size;
    const mbfl_encoding *encoding = mbfl_no2encoding(string->no_encoding);

    if (encoding == NULL) {
        return -1;
    }

    if (encoding->flag & MBFL_ENCTYPE_MBCS) {
        p = string->val;
        n = string->len;
        while (n > 0) {
            char_size = encoding->mbtab[*p];
            p += char_size;  // Possible over-read if char_size is incorrect.
            n -= char_size; // Can underflow if char_size > n.
            count++;
        }
    } else {
        count = string->len;
    }

    return count;
}

