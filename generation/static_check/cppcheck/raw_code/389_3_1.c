typedef struct Node {
    int data;
    struct Node *next;
} Node;

int listPrepend(Node **head, int data) {
    Node *newHead;
    if (head == NULL) return 1;

    newHead = (Node *)malloc(sizeof(Node));
    if (newHead == NULL) {
        perror("Allocation failed");
        return 1;
    }

    newHead->data = data;
    // Missing null check for *head
    newHead->next = (*head)->next;
    *head = newHead;

    return 0;
}