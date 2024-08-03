static void replaceWhitespaceWithUnderscore(char *str) {
    char *cursor;
    while ((cursor = strchr(str, ' ')) != NULL) {
        *cursor = '_';
    }
}

