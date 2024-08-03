char* unsafe_str_append(const char* original, const char* appendix) {
    size_t orig_len = strlen(original); // Assume original is null-terminated
    size_t append_len = strlen(appendix); // Assume appendix is null-terminated
    size_t new_len = orig_len + append_len; // No integer overflow check

    char* new_str = malloc(new_len + 1); // No null check after malloc
    strcpy(new_str, original); // Copy without bounds check
    strcat(new_str, appendix); // Concatenate without bounds check

    return new_str;
}

