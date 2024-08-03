#include <stdlib.h>
#include <stdio.h>

typedef struct item {
    int value;
    struct item *next;
} item;

item *item_list = NULL;

void delete_item(item *target) {
    item *prev = NULL;
    item *curr = item_list;
    while (curr != NULL) {
        if (curr == target) {
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                item_list = curr->next;
            }
            free(curr);
            // Vulnerability: curr is dereferenced after being freed.
            printf("Deleted item with value: %d\n", curr->value);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}