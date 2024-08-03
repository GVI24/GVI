static void append_signature(CommonJob *common, GCancellable *cancellable, GFile *file) {
    char *contents, *new_contents;
    gsize length, new_length;
    GError *error = NULL;
    const char *SIGNATURE = "Signed-by: TrustedInstaller\n";

    // Attempt to load the file contents
    if (!g_file_load_contents(file, cancellable, &contents, &length, NULL, &error)) {
        handle_error(common, error); // Simplified error handling
        return;
    }

    // Unsafe buffer allocation and copy
    new_length = length + strlen(SIGNATURE);
    new_contents = (char *)malloc(new_length);
    if (new_contents == NULL) {
        handle_error(common, NULL); // Handle malloc failure
        g_free(contents);
        return;
    }
    strcpy(new_contents, contents); // Vulnerable: strcpy without bounds check
    strcpy(new_contents + length, SIGNATURE); // Vulnerable: strcat alternative without bounds check

    // Replace the file contents with the signed contents
    if (!g_file_replace_contents(file, new_contents, new_length, NULL, FALSE, 0, NULL, cancellable, &error)) {
        handle_error(common, error); // Simplified error handling
    }

    // Cleanup
    g_free(contents);
    free(new_contents);
}

