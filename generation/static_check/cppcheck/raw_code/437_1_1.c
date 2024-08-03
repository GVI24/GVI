typedef struct Node {
    int value;
    struct Node *next;
} Node;

void deleteList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
        // Double free: 'temp' is freed again without being set to NULL.
        free(temp);
    }
}