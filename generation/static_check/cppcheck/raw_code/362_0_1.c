// Example 1: A function to remove an entry from a linked list based on a condition
typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNode;

void delete_if(ListNode **head, int (*pred)(int)) {
    ListNode *curr = *head;
    ListNode *prev = NULL;
    while (curr != NULL) {
        if (pred(curr->value)) {
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                *head = curr->next;
            }
            free(curr); // Vulnerable: use-after-free if curr is accessed after this point
            // curr is now a dangling pointer
        }
        prev = curr;
        curr = curr->next; // Vulnerable: curr may be a dangling pointer here
    }
}