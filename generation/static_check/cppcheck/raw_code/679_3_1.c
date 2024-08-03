void validate_and_append_path(char *base_path, const char *new_segment) {
    int base_len = strlen(base_path);
    int new_len = strlen(new_segment);
    if ((base_len + new_len + 1) >= PATH_MAX) {
        fprintf(stderr, "Path too long after appending: %s/%s\n", base_path, new_segment);
        return;
    }
    if (base_path[base_len - 1] != '/') {
        strcat(base_path, "/");
    }
    strcat(base_path, new_segment);
}