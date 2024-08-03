static int string_append(char *str, FILE *data) {
    struct string_builder *info = (struct string_builder *) data;
    size_t len = strlen(str);
    
    if (!info->buffer) {
        info->buffer = malloc(64);
        if (!info->buffer) {
            info->fail = 1;
            return -1;
        }
        info->alloc = 64;
        info->len = 0;
    }
    
    while (info->len + len >= info->alloc) {
        char *newbuf = realloc(info->buffer, info->alloc + len);
        if (!newbuf) {
            info->fail = 1;
            return -1;
        }
        info->buffer = newbuf;
        info->alloc += len;
    }
    
    strcpy(&info->buffer[info->len], str);
    info->len += len;
    
    return 0;
}

