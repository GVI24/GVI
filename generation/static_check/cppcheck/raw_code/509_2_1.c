void status_update(proto_tree *tree, const char *status, ...) {
    va_list args;
    va_start(args, status);
    char formatted_status[256];
    vsnprintf(formatted_status, sizeof(formatted_status), status, args); // Vulnerable usage
    // Simulating adding status to a tree node
    proto_tree_add_text_node(tree, formatted_status); // Hypothetical function
    va_end(args);
}

