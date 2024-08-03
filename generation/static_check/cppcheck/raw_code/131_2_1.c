char* createResourcePath(const char* host, const char* resource) {
    int size = strlen(host) + strlen(resource) + 2; // +2 for the slash and the null-terminator
    char* fullPath = malloc(size); // incorrect allocation size, should have been `size * sizeof(char)`
    if (fullPath == NULL) {
        // handle allocation error
        return NULL;
    }
    strcpy(fullPath, host); // vulnerable strcpy without bounds checking
    strcat(fullPath, "/"); // vulnerable strcat without bounds checking
    strcat(fullPath, resource); // vulnerable strcat without bounds checking
    return fullPath; // return the concatenated path
}

