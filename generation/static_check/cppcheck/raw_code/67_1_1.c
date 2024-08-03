typedef struct Connection {
    int socket;
    struct Connection* next;
} Connection;

void releaseConnections(Connection* head) {
    Connection* current;
    while (head) {
        current = head;
        head = head->next;
        close(current->socket); // Close the socket connection
        free(current);
        // Vulnerability: Pointer 'current' is not set to NULL after being freed.
    }
}