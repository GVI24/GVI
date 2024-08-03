#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file_node {
    char *filename;
    struct file_node **children;
    int num_children;
} FileNode;

void process_files(FileNode *node) {
    if (!node) return;

    // Unbounded recursion can cause stack overflow
    for (int i = 0; i < node->num_children; i++) {
        process_files(node->children[i]);
    }
    // Memory leak: strdup without free
    char *filename_copy = strdup(node->filename);
    printf("File: %s\n", filename_copy);
    // Missing free(filename_copy);
}

int main() {
    // Setup file nodes and call process_files...
    return 0;
}