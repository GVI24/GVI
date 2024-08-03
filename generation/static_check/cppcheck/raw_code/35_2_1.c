static void code_snippet_executer(GtkDialog *dialog, int response_id, CodeExecParams *params) {
    gchar *code_snippet;
    switch (response_id) {
        case RESPONSE_EXEC_CODE: {
            code_snippet = gtk_text_view_get_text(GTK_TEXT_VIEW(params->text_view));
            DEBUG("Executing code snippet: %s", code_snippet);
            char *filename = write_to_temp_file(code_snippet);
            char *command = g_strdup_printf("gcc -o temp_exec %s && ./temp_exec", filename);
            system(command); // Vulnerable: Executing uncompiled code from temp file
            g_free(filename);
            g_free(command);
        }
        break;
        default:
            break;
    }
    gtk_widget_destroy(GTK_WIDGET(dialog));
    g_free(params);
}

