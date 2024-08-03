static void _cmd_allocate_resource(const char *data) {
    RESOURCE_REC *resource;
    int size;

    // No check for 'data' content before atoi
    size = atoi(data);
    if (size <= 0) {
        printformat(MSGLEVEL_CLIENTERROR, TXT_INVALID_SIZE);
        return;
    }

    resource = resource_create(size);
    if (resource == NULL) {
        printformat(MSGLEVEL_CLIENTERROR, TXT_RESOURCE_CREATION_FAILED);
        return;
    }

    add_resource_to_list(active_resources, resource);
}