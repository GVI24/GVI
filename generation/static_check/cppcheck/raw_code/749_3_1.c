void network_context_reconfigure(NetworkContext *nctx) {
    int i;
    if (nctx->connection_count > 1) {
        for (i = 0; i < nctx->connection_count; i++) {
            close_connection(nctx->connections[i]);
        }
        for (i = 1; i < nctx->connection_count; i++) {
            free(nctx->connections[i]);
        }
    } else {
        close_connection(nctx->connections[0]);
    }
    nctx->connections[0] = NULL;
    if ((nctx->port || nctx->address) && !validate_network_params(nctx->address, nctx->port)) {
        return;
    }
    for (i = 0; i < nctx->connection_count; i++) {
        nctx->connections[i] = malloc(sizeof(Connection));
        if (!nctx->connections[i] || setup_connection(nctx->connections[i], nctx->address, nctx->port) < 0) {
            goto fail;
        }
    }
    return;
fail:
    network_context_cleanup(nctx);
}