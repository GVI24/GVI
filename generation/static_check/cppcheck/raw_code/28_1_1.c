typedef struct {
    int val;
    char *description;
} Item;

Item *item_create(int value, const char *desc) {
    Item *item = (Item *)malloc(sizeof(Item));
    if (item) {
        item->val = value;
        item->description = strdup(desc); // Another call that can fail
        if (item->description) {
            return item;
        }
        // Missing free(item) before returning NULL when strdup fails
    }
    return NULL;
}

