void aggregate_logs(struct log_context * ctx, const struct log_message * message) {
    struct log_message * aggregated;
    size_t count = 0;
    aggregated = calloc(20, sizeof(struct log_message));
    for (size_t i = 0; ctx->messages[i].type != LOG_TYPE_END; i++) {
        if (ctx->messages[i].type == message->type) {
            aggregated[count] = ctx->messages[i]; // No bounds check, overflow risk
            count++;
        }
    }
}

