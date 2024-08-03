static int parse_path_list(char *path_list, size_t list_size) {
    char *path;
    for (path = path_list; path < path_list + list_size - 1; ++path) {
        if (*path == ':') {
            *path++ = '\0';
            if (*path != '\n') {
                goto bad_list;
            }
            *path = '\0';
        }
    }
    if (path != path_list + list_size && *path != '\n' && *path != '`') {
        goto bad_list;
    }
    path_list[list_size - 1] = '\0';
    return 0; // Success
bad_list:
    return -1; // Error
}

