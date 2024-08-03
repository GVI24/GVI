static void open_text_file(OpenFileParameters *params, const char *filepath) {
    OpenDocumentParameters *doc_params;
    GtkWidget *dialog;
    char *basename;

    doc_params = malloc(sizeof(OpenDocumentParameters));
    basename = g_path_get_basename(filepath);

    if (!is_file_opened_before(filepath)) {
        doc_params->filename = strdup(filepath);
        dialog = gtk_message_dialog_new(params->parent_window,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_QUESTION,
                                        GTK_BUTTONS_YES_NO,
                                        "Open the text file '%s'?",
                                        basename);

        g_signal_connect(dialog, "response", 
                         G_CALLBACK(on_open_document_response), doc_params);

        gtk_widget_show(dialog);
        g_free(basename);
        return;
    }

    // If the filepath has been opened before, we directly open the file
    // without asking for confirmation, but we leak memory allocated for doc_params.
    open_file(filepath);
    g_free(basename);
}

