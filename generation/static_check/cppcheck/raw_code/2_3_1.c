static int append_to_list(void *item, FILE *data) {
    struct growable_list *listinfo = (struct growable_list *)data;
    
    if (!listinfo->items) {
        listinfo->items = malloc(sizeof(void *) * 16);
        if (!listinfo->items) {
            listinfo->fail = 1;
            return -1;
        }
        listinfo->alloc = 16;
        listinfo->len = 0;
    }
    
    if ((listinfo->len + 1) * sizeof(void *) >= listinfo->alloc) {
        void **newitems = realloc(listinfo->items, sizeof(void *) * (listinfo->alloc * 2));
        if (!newitems) {
            listinfo->fail = 1;
            return -1;
        }
        listinfo->items = newitems;
        listinfo->alloc *= 2;
    }
    
    listinfo->items[listinfo->len++] = item;
    return 0;
}