void release_resources(ResourceManager *rm, int should_remove) {
    for (int i = 0; i < rm->resource_count; i++) {
        if (rm->resources[i].data && !rm->resources[i].in_use && (should_remove || &rm->resources[i] != rm->current_resource)) {
            free(rm->resources[i].data);
            // Potential use-after-free if data is accessed after this point
        }
    }
}

