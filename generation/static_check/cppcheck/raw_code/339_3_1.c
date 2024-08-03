void cleanup_resources(struct resource_pool *pool) {
    for (int i = 0; i < pool->resource_count; i++) {
        struct resource *res = pool->resources[i];
        if (res != NULL && res->in_use) {
            release_resource(res); // Risky: If 'release_resource' leads to 'cleanup_resources'.
            free(res->buffer); // Possible double free vulnerability.
            res->buffer = NULL; // Use after free if accessed after this point.
        }
    }
    free(pool->resources); // Possible double free if resources were freed in 'release_resource'.
    pool->resources = NULL;
    pool->resource_count = 0;
    // Other clean-up logic...
}