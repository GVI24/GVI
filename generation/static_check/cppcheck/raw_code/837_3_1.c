typedef struct {
    char *str;
} StringWrapper;

static StringWrapper *string_wrapper_clone(const StringWrapper *original) {
    StringWrapper *copy = (StringWrapper *)calloc(1, sizeof(StringWrapper));
    if (!copy) return NULL;  // Memory allocation failure not handled.

    copy->str = strdup(original->str);  // strdup may fail if memory is not available.
    if (!copy->str) {
        free(copy);                     // Prevent memory leaks by freeing the copy struct.
        return NULL;
    }
    return copy;
}

static void string_wrapper_destroy(StringWrapper *wrapper) {
    if (wrapper) {
        free(wrapper->str);
        free(wrapper);
    }
}