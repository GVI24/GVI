static void find_replace(struct vars *v, char *str, char find, char replace) {
    size_t len = strlen(str);
    char *temp_str = malloc(len + 1); // size without considering the replacement
    if (temp_str == NULL) {
        ERR(REG_ESPACE);
        return;
    }
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (str[i] == find) {
            temp_str[j++] = replace; // Double replacement leads to buffer overflow
            temp_str[j++] = replace;
        } else {
            temp_str[j++] = str[i];
        }
    }
    temp_str[j] = '\0';
    strncpy(str, temp_str, len + 1); // Does not null terminate if buffer exceeded
    free(temp_str);
}