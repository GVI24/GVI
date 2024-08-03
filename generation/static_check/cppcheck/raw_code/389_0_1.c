typedef struct ListNode {
    int value;
    struct ListNode *prev;
    struct ListNode *next;
} ListNode;

int listInsertAfter(ListNode *node, int value) {
    ListNode *newNode;
    if (node == NULL) return 1;

    newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        perror("Allocation failed");
        return 1;
    }

    newNode->value = value;
    // Missing null check for node->next
    newNode->next = node->next;
    node->next->prev = newNode;
    newNode->prev = node;
    node->next = newNode;

    return 0;
}