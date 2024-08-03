static gchar * generate_report(const gchar *username, const gchar *user_input) {
    gchar report[1024];
    // Wrong: Incorporating user-supplied input directly into formatting function
    sprintf(report, "Report for %s: %s", username, user_input);
    return g_strdup(report);
}

