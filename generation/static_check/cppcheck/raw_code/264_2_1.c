const char* find_compatible_charset(charset_list *list, const char *sample) {
    charset_entry *entry;
    const char *compatible = NULL;
    int i = 0;
    while (i < list->num_entries) {
        entry = list->entries[i]; // Missing NULL check for list
        if (entry && is_compatible(entry, sample)) {
            compatible = entry->name;
            break;
        }
        i++;
    }
    return compatible;
}

