bool add_node_vuln(network_t *net) {
    char node_name[MAX_STRING_SIZE];
    char data[MAX_DATA_SIZE];
    if (sscanf(net->input_buffer, "%*s " MAX_STRING " " MAX_DATA, node_name, data) != 2) {
        log_error("Failed to parse ADD_NODE command.");
        return false;
    }

    if (!validate_node_name(node_name)) {
        log_error("Invalid node name supplied for ADD_NODE command.");
        return false;
    }

    node_t *node = create_node(node_name, data);
    if (!node) {
        log_error("Failed to create node for ADD_NODE command.");
        return false;
    }

    if (!insert_node_into_graph(net->graph, node)) {
        log_error("Failed to insert node into graph.");
        return false;
    }

    log_info("Node added successfully to the graph.");
    return true;
}

