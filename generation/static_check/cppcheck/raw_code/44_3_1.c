static void handle_file_transfer(struct file_transfer *transfer) {
    struct file_chunk *chunk = transfer->current_chunk;
    // Check if the chunk transfer is complete
    if (chunk && chunk->state == CHUNK_TRANSFERRED) {
        // Trigger the chunk completion callback, possibly accessing the chunk object
        chunk->on_complete(chunk, chunk->cb_arg);
        // Free the chunk right after the callback is called
        free_file_chunk(chunk);
        transfer->current_chunk = NULL;
    }
}

// Helper functions for cleanup
void net_request_destroy(struct net_request *request) {
    if (request) {
        free(request->data);
        free(request);
    }
}

void free_session_command(struct session_command *cmd) {
    free(cmd->data);
    free(cmd);
}

void free_client_request(struct client_request *req) {
    free(req->payload);
    free(req);
}

void free_file_chunk(struct file_chunk *chunk) {
    free(chunk->data);
    free(chunk);
}