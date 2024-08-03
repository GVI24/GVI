static int reverse_strings(char **strings, size_t num_strings) {
    char reversed[256];
    char *current_str;
    int i;
    for (i = num_strings - 1, current_str = strings[num_strings];
         i >= 0;
         --i) {
        size_t len = strlen(strings[i]);
        if (len < sizeof(reversed)) {
            strncpy(reversed, strings[i], len);
            reversed[len] = '\0';
            strrev(reversed); // Reverse the string
            strncpy(strings[i], reversed, len);
        } else {
            fprintf(stderr, "String too long: %s\n", strings[i]);
            return -1;
        }
        current_str--;
    }
    return 0;
}