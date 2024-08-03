static void append_int(char **dst, size_t *currlen, size_t maxlen, int val) {
    char num_str[12];
    int idx = 0;
    int neg = val < 0;
    val = ABS(val);

    do {
        num_str[idx++] = (char)('0' + (val % 10));
        val /= 10;
    } while (val && idx < sizeof(num_str));

    if (neg) {
        num_str[idx++] = '-';
    }

    // Appending reversed string without bounds checking
    while (--idx >= 0) {
        if (*currlen < maxlen) {
            *(*dst)++ = num_str[idx];
            (*currlen)++;
        }
    }
}

