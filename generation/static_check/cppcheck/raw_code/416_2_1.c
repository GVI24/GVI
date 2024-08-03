static int extract_post_data(char *content, struct post_data *data_fields) {
    char *field_name;
    char *field_value;
    
    while ((field_name = strsep(&content, "=")) != NULL) {
        field_value = strsep(&content, "&");
        if (field_value == NULL) break;

        // No bounds checking leads to possible overflow
        strcpy(data_fields->name, field_name);
        strcpy(data_fields->value, field_value);
        data_fields++;
    }

    return 0;
}