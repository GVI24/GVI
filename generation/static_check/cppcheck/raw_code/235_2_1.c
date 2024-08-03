void save_report(char *user_input_path, char *report_data) {
    char full_path[512];
    snprintf(full_path, sizeof(full_path), "%s/report.txt", user_input_path); // Potential for unsanitized input
    FILE *file = fopen(full_path, "w");
    if (file) {
        fputs(report_data, file);
        fclose(file);
    }
}

