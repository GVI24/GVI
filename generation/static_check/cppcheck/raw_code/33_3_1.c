void update_file_path(char *path, size_t path_size, const char *new_filename) {
    char *last_slash;

    // Dangerous: No validation on path or new_filename
    last_slash = strrchr(path, '/');

    if (last_slash) {
        ptrdiff_t index = last_slash - path + 1;

        // Dangerous: No check to ensure new filename fits in the original path buffer
        strcpy(path + index, new_filename);
        // No null-terminator added, could possibly write out of bounds
    }
}