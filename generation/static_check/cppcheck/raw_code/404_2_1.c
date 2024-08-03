static size_t dangerous_sprintf_wrapper(char *output, size_t output_size, int number) {
    char temp[BUFFER_SIZE];
    int len = sprintf(temp, "%d", number);

    if (len > 2 && len < BUFFER_SIZE) {
        memmove(temp + 2, temp, len); // Potential overflow if len is not checked properly
        temp[0] = '0';
        temp[1] = 'x';
        len += 2;
    }

    memcpy(output, temp, len > output_size ? output_size : len); // Wrong length condition

    // Additional logic...
    return (size_t)len;
}

