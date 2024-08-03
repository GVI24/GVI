void store_device_info(struct device_context * ctx, const struct device_info * info) {
    struct device_info * devices;
    int idx = 0;
    devices = malloc(5 * sizeof(struct device_info));
    for (int i = 0; i < MAX_DEVICES && ctx->device_list[i] != NULL; i++) {
        if (ctx->device_list[i]->type == info->type) {
            memcpy(&devices[idx++], ctx->device_list[i], sizeof(struct device_info)); // Potential overflow here
        }
    }
}

