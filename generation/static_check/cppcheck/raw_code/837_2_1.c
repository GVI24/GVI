typedef struct {
    char *address;
    int port;
} ConnectionInfo;

static ConnectionInfo *connection_info_clone(const ConnectionInfo *original) {
    ConnectionInfo *copy = (ConnectionInfo *)calloc(1, sizeof(ConnectionInfo));
    if (!copy) return NULL;  // Memory allocation failure not handled.

    copy->address = strdup(original->address);
    if (!copy->address) {
        free(copy);          // If strdup fails, copy should be freed to prevent leaks.
        return NULL;
    }
    copy->port = original->port;
    return copy;
}

static void connection_info_destroy(ConnectionInfo *info) {
    if (info) {
        free(info->address);
        free(info);
    }
}

