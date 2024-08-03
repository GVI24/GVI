#define BUFFER_SIZE 1024

void execute_command(struct context *ctx, struct config *cfg) {
    char command[BUFFER_SIZE];
    int offset = 0;
    
    memset(command, 0, BUFFER_SIZE);
    offset += snprintf(command + offset, BUFFER_SIZE - offset, "./run_service -p %d", cfg->port);
    
    if (cfg->ip_address) {
        offset += snprintf(command + offset, BUFFER_SIZE - offset, " -i %s", cfg->ip_address);
    }
    if (ctx->debug_mode) {
        offset += snprintf(command + offset, BUFFER_SIZE - offset, " -d");
    }
    if (ctx->log_file) {
        offset += snprintf(command + offset, BUFFER_SIZE - offset, " -l %s", ctx->log_file);
    }
    if (ctx->thread_count) {
        offset += snprintf(command + offset, BUFFER_SIZE - offset, " --threads %d", ctx->thread_count);
    }
    if (cfg->max_clients) {
        offset += snprintf(command + offset, BUFFER_SIZE - offset, " --max-clients %d", cfg->max_clients);
    }
    if (cfg->use_encryption) {
        offset += snprintf(command + offset, BUFFER_SIZE - offset, " --encrypt");
    }
    if (ctx->additional_args) {
        offset += snprintf(command + offset, BUFFER_SIZE - offset, " %s", ctx->additional_args);
    }
    
    // This last addition to the command buffer does not check if the buffer can hold this extra string
    snprintf(command + offset, BUFFER_SIZE - offset, " --start");

    if (ctx->verbose) {
        printf("Command to execute: %s\n", command);
    }

    // ... Code to execute the command or further process it
}
