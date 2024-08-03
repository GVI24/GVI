char * vec_to_csv(const int *vec, size_t length) {
    size_t buffer_size = length * (10 + 1); // Assuming max 10 digits per integer + comma
    char *csv_str = malloc(buffer_size);
    if (!csv_str) return NULL;
    char *p = csv_str;
    for (size_t i = 0; i < length; i++) {
        // Vulnerability: sprintf used without bounds check
        p += sprintf(p, "%d,", vec[i]);
    }
    if (length > 0) {
        *(p - 1) = '\0'; // Overwrite the last comma
    }
    return csv_str;
}

