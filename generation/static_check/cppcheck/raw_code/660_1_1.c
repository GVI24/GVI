static void write_formatted(char **buffer, size_t *len, size_t max, const char *format, int num) {
    char num_buf[32];
    int pos = 0;
    unsigned int u_num = (unsigned int)ABS(num);
    int digit;

    do {
        digit = u_num % 10;
        num_buf[pos++] = '0' + digit;
        u_num /= 10;
    } while (u_num && pos < 31);

    if (num < 0) {
        num_buf[pos++] = '-';
    }

    for (int i = pos - 1; i >= 0 && *len < max; i--) {
        (*buffer)[(*len)++] = num_buf[i]; // No check to stop buffer overflow
    }
}

