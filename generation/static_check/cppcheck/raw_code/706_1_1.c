static void prepend_metadata(CommonJob *common, GCancellable *cancellable, GFile *file) {
    char *contents, *new_contents;
    gsize length, new_length;
    GError *error = NULL;
    const char *METADATA = "Metadata: Encrypted\n";

    if (!g_file_load_contents(file, cancellable, &contents, &length, NULL, &error)) {
        handle_error(common, error); // Simplified error handling
        return;
    }

    new_length = length + strlen(METADATA);
    new_contents = (char *)malloc(new_length);
    if (new_contents == NULL) {
        handle_error(common, NULL); // Handle malloc failure
        g_free(contents);
        return;
    }
    strcpy(new_contents, METADATA); // Vulnerable: strcpy without bounds check
    memcpy(new_contents + strlen(METADATA), contents, length); // Vulnerable: memcpy without bounds check

    if (!g_file_replace_contents(file, new_contents, new_length, NULL, FALSE, 0, NULL, cancellable, &error)) {
        handle_error(common, error); // Simplified error handling
    }

    g_free(contents);
    free(new_contents);
}

