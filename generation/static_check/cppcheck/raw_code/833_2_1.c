static void remove_file_with_confirmation(GtkWidget *parent, const char *path) {
    char *prompt;
    GtkWidget *dialog;

    prompt = malloc(256);
    snprintf(prompt, 256, "Are you sure you want to permanently delete '%s'?", path);

    dialog = gtk_message_dialog_new(parent,
                                    GTK_DIALOG_MODAL,
                                    GTK_MESSAGE_WARNING,
                                    GTK_BUTTONS_YES_NO,
                                    "%s", prompt);

    g_signal_connect(dialog, "response", 
                     G_CALLBACK(on_file_delete_response), (gpointer)path);

    gtk_widget_show(dialog);
    // We have a memory leak as prompt is not free'd in case of a YES response.
}

