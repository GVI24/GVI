void append_extension(char *file_path, size_t path_len, const char *extension) {
    size_t ext_len = strlen(extension);

    // Path concatenation without size check can cause buffer overflow
    if (file_path[path_len - 1] != '.') {
        file_path[path_len] = '.';
        path_len++;
    }

    // Dangerous: No check for buffer overrun
    for (size_t i = 0; i < ext_len; ++i) {
        file_path[path_len + i] = extension[i];
    }
    // No null-terminator added, leading to potential undefined behavior
}

