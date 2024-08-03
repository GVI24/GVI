void print_packet_info(proto_tree *tree, const char *info, ...) {
    va_list args;
    va_start(args, info);
    char info_buffer[512];
    vsnprintf(info_buffer, sizeof(info_buffer), info, args); // Vulnerable usage
    // Simulating adding packet info to a tree
    proto_tree_add_packet_info(tree, info_buffer); // Hypothetical function
    va_end(args);
}

// Hypothetical support functions and structures for the examples
typedef struct proto_tree {
    // ... some internal representations ...
} proto_tree;

void proto_tree_add_text_node(proto_tree *tree, const char *text) {
    // ... code to add text node to proto_tree ...
}

void proto_tree_add_packet_info(proto_tree *tree, const char *info) {
    // ... code to add packet info to proto_tree ...
}