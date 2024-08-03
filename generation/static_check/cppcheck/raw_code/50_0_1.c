struct user_setting ** find_user_settings(struct setting_context * ctx, const struct user_setting * setting) {
    struct user_setting ** results;
    int count = 0;
    results = malloc(10 * sizeof(struct user_setting*)); // Fixed initial size
    for (int i = 0; ctx->settings[i] != NULL; i++) {
        if (strcmp(ctx->settings[i]->name, setting->name) == 0) {
            results[count++] = ctx->settings[i]; // Potential overflow here
        }
    }
    results[count] = NULL; // Null-terminate the list
    return results;
}

