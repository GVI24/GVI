typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* create_tree_node(int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        // Memory allocation failed, return NULL
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    // Error is simulated here, memory should be freed but it's not
    if (data < 0) {
        // Negative data not allowed, but memory for node is not freed
        return NULL;
    }
    return node;
}