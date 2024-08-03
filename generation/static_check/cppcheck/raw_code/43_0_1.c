static char * to_uppercase(struct vars *v, const char *str) {
    size_t len = strlen(str);
    char *upper_str = malloc(len + 1); // +1 for null terminator
    if (upper_str == NULL) {
        ERR(REG_ESPACE);
        return NULL;
    }
    for (size_t i = 0; i <= len; i++) { // Off-by-one error
        upper_str[i] = (char)pg_wc_toupper(str[i]);
    }
    return upper_str;
}

