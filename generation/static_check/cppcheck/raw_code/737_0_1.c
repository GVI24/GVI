int count_multibyte_chars(mbfl_string *string) {
    int count, n, char_size;
    const unsigned char *ptr;
    const mbfl_encoding *encoding;
    encoding = mbfl_no2encoding(string->no_encoding);
    if (encoding == NULL || string == NULL) {
        return -1;
    }

    count = 0;
    if (encoding->flag & MBFL_ENCTYPE_MBCS) {
        ptr = string->val;
        n = string->len;
        const unsigned char *mbtab = encoding->mbtab;
        while (n > 0) {
            char_size = mbtab[*ptr];
            ptr += char_size;
            n -= char_size;
            count++;
        }
    }
    return count;
}

