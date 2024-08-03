typedef struct {
    GtkWidget *editor;
    char *document_path;
} SaveDocumentData;

static void prompt_save_changes(SaveDocumentData *data) {
    GtkWidget *dialog;

    if (has_unsaved_changes(data->editor)) {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_QUESTION,
                                        GTK_BUTTONS_YES_NO,
                                        "Document '%s' has unsaved changes. Save before closing?",
                                        data->document_path);

        g_signal_connect(dialog, "response", 
                         G_CALLBACK(on_save_changes_response), data);

        gtk_widget_show(dialog);
        // If there are no unsaved changes, we don't show the dialog 
        // but we also don't free the data structure.
    } else {
        close_editor(data->editor);
    }
}