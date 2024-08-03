#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *content;
    struct node *prev;
} node;

node *head = NULL;

void remove_node(node *target) {
    if (target->prev) {
        target->prev->next = target->next;
    }
    free(target->content);
    free(target); // Vulnerability: pointer 'target' not set to NULL after free.
    // Some other function might try to access 'target', causing use-after-free.
}