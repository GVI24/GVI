static void network_connection_handle(struct net_connection *conn) {
    struct net_request *request = conn->current_request;
    if (request->completed) {
        conn->state = NET_IDLE;
        // Call the user callback, potentially using the request object
        (*request->on_complete)(request, request->user_data);
        // Immediately free the request without ensuring the callback does not use it afterward
        net_request_destroy(request);
    }
}

