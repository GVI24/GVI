bool remove_node_vuln(network_t *net) {
    char node_name[MAX_STRING_SIZE];
    if (sscanf(net->input_buffer, "%*s " MAX_STRING, node_name) != 1) {
        log_error("Failed to parse REMOVE_NODE command.");
        return false;
    }

    if (!delete_node_from_graph(net->graph, node_name)) {
        log_warning("Node not found or could not be removed.");
        return false;
    }

    log_info("Node removed successfully from the graph.");
    return true;
}

