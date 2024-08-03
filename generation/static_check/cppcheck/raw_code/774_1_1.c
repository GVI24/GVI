bool update_node_info(network_t *net) {
    char node_name[MAX_STRING_SIZE];
    char new_info[MAX_INFO_SIZE];
    if (sscanf(net->input_buffer, "%*s " MAX_STRING " " MAX_INFO, node_name, new_info) != 2) {
        log_error("Failed to parse UPDATE_NODE command.");
        return false;
    }

    node_t *node = find_node_by_name(net->graph, node_name);
    if (!node) {
        log_error("Node not found for UPDATE_NODE command.");
        return false;
    }

    strncpy(node->info, new_info, sizeof(node->info));
    node->info[sizeof(node->info) - 1] = '\0';

    log_info("Node info updated successfully.");
    return true;
}

