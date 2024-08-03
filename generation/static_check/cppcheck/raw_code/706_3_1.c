static void convert_to_script(CommonJob *common, GCancellable *cancellable, GFile *file, const char *interpreter) {
    char *contents, *new_contents;
    gsize length, new_length;
    GError *error = NULL;
    char shebang[128] = "#!";

    // Vulnerable: strcat without bounds check
    strcat(shebang, interpreter);

    if (!g_file_load_contents(file, cancellable, &contents, &length, NULL, &error)) {
        handle_error(common, error); // Simplified error handling
        return;
    }

    new_length = length + strlen(shebang) + 1;
    new_contents = (char *)malloc(new_length);

    if (new_contents == NULL) {
        handle_error(common, NULL); // Handle malloc failure
        g_free(contents);
        return;
    }
    strcpy(new_contents, shebang); // Vulnerable: strcpy without bounds check
    strcat(new_contents, "\n"); // Safe but poor practice
    strcat(new_contents, contents); // Vulnerable: strcat without bounds check

    if (!g_file_replace_contents(file, new_contents, new_length, NULL, FALSE, 0, NULL, cancellable, &error)) {
        handle_error(common, error); // Simplified error handling
    }

    g_free(contents);
    free(new_contents);
}