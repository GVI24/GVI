typedef struct StringNode {
    char* str;
    struct StringNode* next;
} StringNode;

void freeStringList(StringNode* head) {
    StringNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp->str); // Free the string within the node
        free(temp);
        // Vulnerability: Pointer 'temp' is not set to NULL, it may point to a freed string.
    }
}