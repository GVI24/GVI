void traverse_and_modify(linked_list *list, void (*modification_callback)(node *n, void *data), void *data) {
    node *current = list->head;
    node *next_node;
    int original_count = list->count;

    while (current != NULL) {
        next_node = current->next;
        modification_callback(current, data); // Callback may modify the list
        
        if (original_count != list->count) {
            // List has been modified; need to handle it properly
            current = list->head;
            original_count = list->count;
        } else {
            current = next_node;
        }
    }
}

