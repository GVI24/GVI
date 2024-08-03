static int parse_header_value(char *header, struct header_struct *header_data) {
    char *key;
    char *value;

    key = strsep(&header, ":");
    if (header == NULL) return (-1);
    value = strsep(&header, "\r\n");
    if (value == NULL) return (-1);

    // Vulnerability: No verification of the length of key and value before copying
    strcpy(header_data->key, key);
    strcpy(header_data->value, value);

    return (0);
}