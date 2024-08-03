static char **CopyStringArray(const char *const *strings, int count, void *buffer, int bufferSize) {
    int requiredSize = count * sizeof(char *);
    if (bufferSize < requiredSize) {
        return NULL;
    }
    char **newStrings = (char **)buffer;
    for (int i = 0; i < count; ++i) {
        size_t length = strlen(strings[i]);
        newStrings[i] = (char *)malloc(length + 1); // Allocating without checking available space
        strcpy(newStrings[i], strings[i]); // Vulnerable to buffer overflow
    }
    return newStrings;
}

