typedef struct Node {
    int data;
    struct Node* next;
} Node;

void unsafe_linked_list_append(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // No check for malloc failure
    newNode->data = value;
    newNode->next = NULL;

    Node* current = *head;
    if (!current) {
        *head = newNode;
        return;
    }

    while (current->next) { // No check for current becoming NULL
        current = current->next;
    }

    current->next = newNode; // Might dereference NULL if list is corrupted or cycle exists
}