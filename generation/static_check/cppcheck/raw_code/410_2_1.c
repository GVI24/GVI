void delete_temporary_files(GFile *temp_dir, GtkWindow *parent_window) {
    GError *error = NULL;
    GFileEnumerator *enumerator = g_file_enumerate_children(temp_dir, "*", G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS, NULL, &error);

    if (error) {
        g_error_free(error);
        return;
    }

    GFileInfo *file_info;
    while ((file_info = g_file_enumerator_next_file(enumerator, NULL, &error)) != NULL) {
        GFile *file = g_object_ref(g_file_get_child(temp_dir, g_file_info_get_name(file_info)));
        g_file_delete(file, NULL, &error);
        // Error is unchecked. If deletion fails, the file reference is not freed, potentially causing a memory leak.
        // Additionally, if the enumerator is freed before the file_info and file, it could lead to use-after-free.
        g_object_unref(file);
        g_object_unref(file_info);
    }

    g_object_unref(enumerator);
}

