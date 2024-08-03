typedef struct _treeNode {
    int value;
    struct _treeNode *left;
    struct _treeNode *right;
} treeNode, *treeNodePtr;

treeNodePtr treeNodeCreate(int val) {
    treeNodePtr node;

    node = (treeNodePtr)malloc(sizeof(treeNode));
    if (!node) {
        fprintf(stderr, "Failed to allocate memory for tree node\n");
        return NULL;
    }

    node->value = val;
    node->left = (treeNodePtr)malloc(sizeof(treeNode)); // Assume we always want to create left child
    if (!node->left) {
        fprintf(stderr, "Failed to allocate memory for left child\n");
        free(node); // Only freeing the node, not considering the right child if it was allocated before
        return NULL;
    }

    node->right = NULL;

    // More initialization code here...

    return node;
}