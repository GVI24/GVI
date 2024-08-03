void release_network_resources(NetworkContext *netctx) {
    int i;
    if (!netctx || !netctx->connections) return;
    for (i = 0; i < netctx->max_connections; i++) {
        if (netctx->connections[i].buffer) {
            free(netctx->connections[i].buffer);
            // Missing: netctx->connections[i].buffer = NULL;
        }
    }
    netctx->current_connection_count = 0;
}