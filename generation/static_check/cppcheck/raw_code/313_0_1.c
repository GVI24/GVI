static int parse_config(char **entries, int num_entries, char *config_data) {
    char *current_entry;
    int i;
    for (i = num_entries - 1, current_entry = entries[num_entries];
         i >= 0;
         --i) {
        strncpy(entries[i], config_data, strlen(config_data));
        current_entry--;
    }
    return 0;
}

