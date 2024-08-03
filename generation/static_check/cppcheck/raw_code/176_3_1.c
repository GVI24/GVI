void destroyTree(TreeNode *root) {
    if(root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        freeTreeNodeData(root);  // Free associated data with the tree node
        free(root);  // Vulnerability: should set root to NULL after free
        // root is now a dangling pointer
    }
}

// Helper functions for the examples that may have similar vulnerabilities

// Free item contents for Example 1
void freeItemContents(Item *item) {
    if(item->content != NULL) {
        free(item->content);  // Should set item->content to NULL after free
        // item->content is now a dangling pointer
    }
}

// Close connection for Example 2
void closeConnection(int socket) {
    if(close(socket) == -1) {
        // Error handling for failed close
    }
}

// Free tree node data for Example 4
void freeTreeNodeData(TreeNode *node) {
    if(node->data != NULL) {
        free(node->data);  // Should set node->data to NULL after free
        // node->data is now a dangling pointer
    }
}