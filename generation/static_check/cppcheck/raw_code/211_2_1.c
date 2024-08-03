static void add_user_comment(char **comments, const char *comment) {
    if (!comment) return;
    if (*comments) {
        size_t new_size = strlen(*comments) + strlen(comment) + 2; // +2 for space and null terminator
        char *new_comments = realloc(*comments, new_size);
        if (new_comments) {
            strcat(new_comments, " ");
            strcat(new_comments, comment);
            *comments = new_comments; // Potential leak if realloc fails and returns NULL
        }
    } else {
        *comments = strdup(comment);
    }
}

