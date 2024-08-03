static void add_user_comment(CommonJob *common, GCancellable *cancellable, GFile *file, const char *comment) {
    char *contents, *new_contents;
    gsize length, new_length;
    GError *error = NULL;

    if (!g_file_load_contents(file, cancellable, &contents, &length, NULL, &error)) {
        handle_error(common, error); // Simplified error handling
        return;
    }

    new_length = length + strlen(comment) + 1; // +1 for newline
    new_contents = (char *)malloc(new_length);

    if (new_contents == NULL) {
        handle_error(common, NULL); // Handle malloc failure
        g_free(contents);
        return;
    }
    sprintf(new_contents, "%s\n%s", comment, contents); // Vulnerable: sprintf without bounds check

    if (!g_file_replace_contents(file, new_contents, new_length, NULL, FALSE, 0, NULL, cancellable, &error)) {
        handle_error(common, error); // Simplified error handling
    }

    g_free(contents);
    free(new_contents);
}

