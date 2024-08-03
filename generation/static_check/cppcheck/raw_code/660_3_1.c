static void simple_itoa(char **buffer, size_t *offset, size_t buffer_size, int value) {
    char local_buf[11];
    int tmp_value = value;
    int i = 0;
    int negative = tmp_value < 0;

    // Fill the local buffer in reverse order
    do {
        local_buf[i++] = '0' + ABS(tmp_value % 10);
        tmp_value /= 10;
    } while (tmp_value && i < 10);

    if (negative) {
        local_buf[i++] = '-';
    }

    // Now write the local buffer into the main buffer without checking for overflow
    for (int j = i - 1; j >= 0; j--) {
        if (*offset < buffer_size) {
            (*buffer)[(*offset)++] = local_buf[j]; // Overflow can occur here
        }
    }
}