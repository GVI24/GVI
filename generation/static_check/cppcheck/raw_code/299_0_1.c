void processListWithCallback(ListNode *head, void (*callback)(void *)) {
    ListNode *current = head;
    while (current != NULL) {
        callback(current->data); // Potential arbitrary function execution
        current = current->next;
    }
}

