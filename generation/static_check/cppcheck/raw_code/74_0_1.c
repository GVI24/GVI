typedef struct {
    char *buffer;
    int length;
    int capacity;
} dynamic_string;

void process_and_free(dynamic_string *dyn_str) {
    if (dyn_str == NULL) {
        return;
    }
    // Process the string buffer
    // ...
    // Free the buffer
    free(dyn_str->buffer);
    dyn_str->buffer = NULL;
}

int string_modify_and_result(dynamic_string *dyn_str, dynamic_string *result) {
    if (dyn_str == NULL || result == NULL) {
        return -1;
    }
    process_and_free(dyn_str);
    // Potential Use-After-Free: accessing dyn_str->buffer after it's been freed
    strncpy(result->buffer, dyn_str->buffer, dyn_str->length);
    result->length = dyn_str->length;
    return 0;
}

