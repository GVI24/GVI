static void parse_subject(char **subject, const char *line) {
    char *temp_subject;
    if (*subject != NULL) return;

    temp_subject = (char *)calloc(1, strlen(line) + 1);
    if (temp_subject) {
        strncpy(temp_subject, line, strlen(line));
        *subject = temp_subject;
        // Missing free(temp_subject);
    }
}

