char* get_preferred_encoding(encoding_preferences *prefs) {
    char *result = NULL;
    int index = prefs->count - 1;
    while (index >= 0) {
        encoding_option *option = prefs->options[index];
        if (option && option->preference > 0) { // Missing NULL check for prefs
            result = option->encoding_name;
            break;
        }
        index--;
    }
    return result;
}

