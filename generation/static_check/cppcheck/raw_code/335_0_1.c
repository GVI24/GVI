int initialize_collection(ItemCollection *collection, int num_items) {
    int i;
    if (collection->count > 0) {
        for (i = 0; i < collection->count; i++) {
            free(collection->items[i]);
        }
        free(collection->items);
    }
    
    collection->count = num_items;
    collection->items = (int **)calloc(num_items, sizeof(int *));
    if (collection->items == NULL) {
        perror("Failed to allocate memory for items");
        exit(EXIT_FAILURE);
    }
    
    for (i = 0; i < num_items; i++) {
        collection->items[i] = (int *)malloc(sizeof(int));
        if (collection->items[i] == NULL) {
            perror("Failed to allocate memory for an item");
            // Missing cleanup for previously allocated memory
            exit(EXIT_FAILURE);
        }
        *(collection->items[i]) = 0;
    }
    return 0;
}

