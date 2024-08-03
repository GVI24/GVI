typedef struct Node {
    int data;
    struct Node* next;
} Node;

void freeNodeList(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
        // Vulnerability: Pointer 'tmp' is not set to NULL after being freed.
    }
}