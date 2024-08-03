typedef struct list_node {
    void *data;
    struct list_node *next;
} list_node_t;

void list_add_node(list_node_t **head, void *data) {
    list_node_t *new_node = malloc(sizeof(list_node_t));
    if (new_node == NULL) {
        return;
    }
    
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;

    // Increment reference count for the data being added to the list
    data_ref_increment(data);
    // Missing corresponding decrement when the node is removed
}
