typedef struct {
    char *buffer;
    size_t capacity;
    size_t length;
} String;

String *String_create(size_t init_capacity) {
    String *str = (String *)malloc(sizeof(String));
    if (!str) {
        return NULL;
    }

    str->buffer = (char *)malloc(init_capacity);
    if (!str->buffer) {
        // Vulnerability: memory allocated for 'str' is not freed before returning NULL
        return NULL;
    }

    str->buffer[0] = '\0';
    str->capacity = init_capacity;
    str->length = 0;
    return str;
}
