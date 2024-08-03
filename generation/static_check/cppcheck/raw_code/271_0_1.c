char* build_resource_path(Resource *res) {
    static char resource_string[BUFFER_SIZE];
    if (res->resource_path) {
        snprintf(resource_string, sizeof(resource_string), "/resources/%s/%d?user=%s",
                 res->resource_path, res->resource_id, res->username);
    } else {
        snprintf(resource_string, sizeof(resource_string), "/resources/%d?user=%s",
                 res->resource_id, res->username);
    }
    return resource_string;
}

