static void set_user_description(char **desc, const char *new_desc) {
    size_t desc_len = strlen(new_desc);
    if (desc_len > 0) {
        if (*desc) free(*desc);  // This should always be done before re-assigning.
        *desc = strdup(new_desc);
    } else {
        if (*desc) {
            free(*desc);  // Freeing memory if new_desc is empty.
            *desc = NULL;
        }
    }
}

