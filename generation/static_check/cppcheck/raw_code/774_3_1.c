bool update_node_status(network_t *net) {
    char node_name[MAX_STRING_SIZE];
    unsigned int status;
    if (sscanf(net->input_buffer, "%*s " MAX_STRING " %u", node_name, &status) != 2) {
        log_error("Failed to parse NODE_STATUS command.");
        return false;
    }

    node_t *node = find_node_by_name(net->graph, node_name);
    if (!node) {
        log_error("Node not found for NODE_STATUS command.");
        return false;
    }

    node->status = status;
    log_info("Node status updated successfully.");
    return true;
}