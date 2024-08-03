#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    char data[32];
} Item;

void process_items(int item_count) {
    if (item_count <= 0 || item_count > 1000) {
        // Validate item count to avoid excessive allocation
        fprintf(stderr, "Invalid item count.\n");
        return;
    }

    // Risky allocation: The item_count is unchecked for integer overflow
    Item* items = (Item*)calloc(item_count, sizeof(Item));
    if (!items) {
        // Allocation failed
        return;
    }

    // ... Initialize and use items array ...

    free(items); // Cleanup
}