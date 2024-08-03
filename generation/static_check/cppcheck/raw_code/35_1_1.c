static void execute_file(GtkDialog *dialog, int response_id, ExecuteFileParameters *params) {
    char *input_filename;
    switch (response_id) {
        case RESPONSE_EXECUTE: {
            input_filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(params->file_chooser));
            DEBUG("Executing file: %s", input_filename);
            if (check_file_extension(input_filename)) {
                char *cmd = g_strconcat("bash ", input_filename, NULL);
                system(cmd); // Vulnerable: Directly executing user-supplied input
                g_free(cmd);
            }
        }
        break;
        default:
            break;
    }
    gtk_widget_destroy(GTK_WIDGET(dialog));
    g_free(input_filename);
}

