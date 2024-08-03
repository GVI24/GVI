static int sendMessage(struct connection *conn, struct message *msg) {
    int status = sendMessageToSocket(conn->socket, msg);
    freeMessage(msg);
    
    // Use-After-Free: 'msg' is used after it has been freed
    if (msg->status != SUCCESS) {
        logError("Message sending failed");
        return -1;
    }
    
    return status;
}