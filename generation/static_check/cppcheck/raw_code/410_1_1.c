void add_file_to_recent(GFile *file, GtkWindow *parent_window) {
    GError *error = NULL;
    gchar *uri_string = g_file_get_uri(file);
    gtk_recent_manager_add_item(gtk_recent_manager_get_default(), uri_string);

    // uri_string is not freed, leading to a memory leak.
}

