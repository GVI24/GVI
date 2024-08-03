static void process_incoming_message(char *msg, int size, struct client *cl, int tcp_sock) {
    if (validate_client(cl->id) != 0) {
        return;
    }
    cl->last_msg_time = time(NULL);
    memcpy(cl->buffer, msg, size); // No bounds checking
    cl->buffer_size = size;
    if (debug) {
        fprintf(stderr, "Received TCP message, size %d, from client %d\n", cl->buffer_size, cl->id);
    }
    handle_message(tcp_sock, cl->id);
}

