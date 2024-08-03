static void parse_content_disposition(char **disposition, const char *header) {
    char *temp_disposition;
    if (*disposition != NULL) return;

    temp_disposition = (char *)malloc(strlen(header) + 1);
    if (temp_disposition) {
        strcpy(temp_disposition, header);
        *disposition = temp_disposition;
        // Missing free(temp_disposition);
    }
}

