static void open_url_response_handler(GtkDialog *dialog, int response_id, OpenURLParameters *params) {
    const gchar *url;
    switch (response_id) {
        case RESPONSE_OPEN: {
            url = gtk_entry_get_text(GTK_ENTRY(params->url_entry));
            DEBUG("Opening URL: %s", url);
            if (!g_str_has_prefix(url, "http://") && !g_str_has_prefix(url, "https://")) {
                DEBUG("Invalid URL scheme.");
            } else {
                system(g_strdup_printf("xdg-open '%s'", url)); // Vulnerable: Improper command sanitization
            }
        }
        break;
        default:
            break;
    }
    gtk_widget_destroy(GTK_WIDGET(dialog));
    g_free(params);
}

