#define COMMAND_SIZE 256

void create_backup_script(struct backup_context *b_ctx, struct backup_params *b_params) {
    char backup_command[COMMAND_SIZE];
    int written = 0;

    written += snprintf(backup_command, COMMAND_SIZE, "/usr/bin/rsync -avz %s %s", b_params->source, b_params->destination);
    if (b_params->exclude_list) {
        // If the exclude list is too long, it can cause a buffer overflow
        written += snprintf(backup_command + written, COMMAND_SIZE - written, " --exclude-from=%s", b_params->exclude_list);
    }
    if (b_ctx->compress) {
        // This check is insufficient to prevent overflow caused by constant string length
        if (written < COMMAND_SIZE - 12) {
            strcat(backup_command, " --compress");
        }
    }
    
    if (b_ctx->verbose) {
        printf("Backup command: %s\n", backup_command);
    }

    // ... Code to execute the backup command or further process it
}