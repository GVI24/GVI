static int store_user_input(const char *input, FILE *data) {
    struct input_storage *storage = (struct input_storage *) data;
    size_t input_length = strlen(input);
    
    if (!storage->buffer) {
        storage->buffer = malloc(128);
        if (!storage->buffer) {
            storage->fail = 1;
            return -1;
        }
        storage->alloc = 128;
        storage->len = 0;
    }
    
    if (storage->len + input_length >= storage->alloc) {
        size_t new_size = storage->alloc + input_length;
        char *newbuf = realloc(storage->buffer, new_size);
        if (!newbuf) {
            storage->fail = 1;
            return -1;
        }
        storage->buffer = newbuf;
        storage->alloc = new_size;
    }
    
    strcat(storage->buffer, input);
    storage->len += input_length;
    
    return 0;
}

