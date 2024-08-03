void create_user_desktop_link(GFile *file, GtkWindow *parent_window) {
    GError *error = NULL;
    gchar *desktop_path = g_strdup_printf("%s/Desktop", g_get_home_dir());
    GFile *desktop_file = g_file_new_for_path(desktop_path);

    // The file is copied without checking its contents, which may be a script with malicious intent.
    g_file_copy(file, desktop_file, G_FILE_COPY_NONE, NULL, NULL, NULL, &error);

    // The permissions are set to be world-executable, which is a security risk.
    g_file_set_attribute_uint32(desktop_file, "unix::mode", 0777, G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS, NULL, &error);

    if (error) {
        // Error is logged but not handled properly, which could lead to unexpected states.
        g_warning("Failed to create desktop link: %s", error->message);
        g_error_free(error);
    }

    g_free(desktop_path);
    g_object_unref(desktop_file);
}
