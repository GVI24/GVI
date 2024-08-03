#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node **children;
    int child_count;
} Node;

void parse_node(Node *root) {
    if (!root) return;

    // Stack overflow due to deep recursion
    for (int i = 0; i < root->child_count; i++) {
        parse_node(root->children[i]);
    }
    // Memory leak: strdup without free
    char *data_copy = strdup(root->data);
    printf("Data: %s\n", data_copy);
    // Missing free(data_copy);
}

int main() {
    // Setup nodes and call parse_node...
    return 0;
}