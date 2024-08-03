int network_resource_init(NetworkResource *net_res, int socket_count) {
    assert(net_res);

    net_res->sockets = (int *)malloc(socket_count * sizeof(int));
    if (!net_res->sockets) {
        // Failed to allocate memory for sockets, but not cleaning up
        return -1;
    }

    net_res->buffer = (char *)malloc(BUFFER_SIZE);
    if (!net_res->buffer) {
        // Forgot to free net_res->sockets
        free(net_res->sockets); // Correct free, but should be done in all error cases
        return -1;
    }

    net_res->state_flags = (unsigned char *)malloc(socket_count);
    if (!net_res->state_flags) {
        // Forgot to free net_res->sockets and net_res->buffer
        return -1;
    }

    memset(net_res->state_flags, 0, socket_count);
    return 0;
}

