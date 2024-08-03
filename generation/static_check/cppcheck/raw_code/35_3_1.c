static void custom_script_runner(GtkDialog *dialog, int response_id, ScriptParams *parameters) {
    gchar *script_path;
    switch (response_id) {
        case RESPONSE_RUN_SCRIPT: {
            script_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(parameters->file_chooser));
            DEBUG("Running script: %s", script_path);
            char *cmd = g_strdup_printf("/bin/sh %s", script_path);
            if (g_file_test(script_path, G_FILE_TEST_IS_EXECUTABLE)) {
                system(cmd); // Vulnerable: Blindly executing a script file without validation
            }
            g_free(cmd);
        }
        break;
        default:
            break;
    }
    gtk_widget_destroy(GTK_WIDGET(dialog));
    g_free(parameters);
}