void get_directory_name(char *full_path, char *directory_name, size_t dir_size) {
    char *last_slash;

    // Dangerous: No check if full_path is null or not null-terminated
    last_slash = strrchr(full_path, '/');

    if (last_slash) {
        size_t copy_size = last_slash - full_path;
        // Potential buffer overflow if copy_size is greater than dir_size
        memcpy(directory_name, full_path, copy_size);
        // No null-terminator added after copy
    }
}

