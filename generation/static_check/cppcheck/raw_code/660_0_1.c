static void int_to_string(char **dest, size_t *current_len, size_t max_len, int number) {
    char temp[20];
    int i = 0;
    int is_negative = number < 0;
    unsigned int n = ABS(number);

    while (n) {
        temp[i++] = (n % 10) + '0';
        n /= 10;
        if (i >= sizeof(temp) - 1) break; // Preventing overflow in temp array, but not in dest
    }

    if (is_negative) {
        temp[i++] = '-';
    }

    temp[i] = '\0';

    // Reverse the temp string
    for (int j = 0; j < i / 2; j++) {
        char c = temp[j];
        temp[j] = temp[i - j - 1];
        temp[i - j - 1] = c;
    }

    // Copy to dest without proper bounds check
    while ((*current_len < max_len) && *temp) {
        *(*dest)++ = *temp++;
        (*current_len)++;
    }
}

