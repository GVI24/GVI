static void process_client_request(struct client_context *ctx) {
    struct client_request *req = ctx->active_request;
    // Check if the request is ready to be processed
    if (req && req->status == REQUEST_READY) {
        // Run the associated request handler which may use the request object
        req->handler(req, req->handler_arg);
        // Free the request object immediately after handler invocation
        free_client_request(req);
        ctx->active_request = NULL;
    }
}

