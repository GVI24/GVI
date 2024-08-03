static int buffer_scan_and_mark(char *buffer, size_t buf_size, char mark) {
    size_t index = 0;
    if (!buffer) {
        return -1;
    }

    while (index < buf_size) {
        if (buffer[index] == '\0') {
            buffer[index] = mark; // Potential write past buffer if index == buf_size - 1
        }
        index++; // Unsafe increment, may lead to out-of-bounds access
    }

    return 0;
}

