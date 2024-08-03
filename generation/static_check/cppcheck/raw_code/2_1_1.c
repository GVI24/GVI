static int int_array_insert(int value, FILE *data) {
    struct int_array *info = (struct int_array *) data;
    
    if (!info->array) {
        info->array = malloc(sizeof(int) * 10);
        if (!info->array) {
            info->fail = 1;
            return -1;
        }
        info->alloc = 10;
        info->len = 0;
    }
    
    if (info->len >= info->alloc) {
        int *newarray = realloc(info->array, sizeof(int) * (info->alloc * 2));
        if (!newarray) {
            info->fail = 1;
            return -1;
        }
        info->array = newarray;
        info->alloc *= 2;
    }
    
    info->array[info->len++] = value;
    return value;
}

