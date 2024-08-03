#include <stdlib.h>

typedef struct {
    int socket;
    // Other connection-related fields...
} HTTPConnection;

void close_http_connection(HTTPConnection *conn) {
    // Vulnerability: Double free if close_http_connection is called twice on the same connection
    close(conn->socket);
    free(conn);
    conn = NULL; // Setting the pointer to NULL after free is a good practice but does not prevent double free.
}

// Example usage:
// HTTPConnection *conn = create_connection();
// close_http_connection(conn);
// close_http_connection(conn); // Double free if called again