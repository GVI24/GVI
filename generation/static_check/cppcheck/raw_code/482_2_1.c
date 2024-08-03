typedef struct treeNode {
    void *data;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

int insertTreeNode(treeNode **root, void *data) {
    if (root == NULL) return 0;
    
    treeNode *newNode = (treeNode *)malloc(sizeof(treeNode));
    if (newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory for tree node\n");
        return 0;
    }
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    if (*root == NULL) {
        *root = newNode;
    } else {
        // Here we would typically have logic to insert the node correctly,
        // but if it fails, the memory for newNode is leaked
    }
    
    return 1;
}

