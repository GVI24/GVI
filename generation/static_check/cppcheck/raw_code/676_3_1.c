int handle_secure_command(struct context *ctx, unsigned char *command, int command_length) {
    if (command_length < MIN_COMMAND_SIZE) {
        // Log error, command length too short
        return -1;
    }

    struct command_struct *cmd = (struct command_struct *)command;

    if (cmd->command_type != EXPECTED_COMMAND_TYPE) {
        // Log error, unexpected command type
        return -1;
    }

    if (validate_ctx(ctx, cmd->context_id) != 0) {
        // Log error, invalid context for the command
        return -1;
    }

    unsigned char *command_data = command + sizeof(struct command_struct);
    int data_length = command_length - sizeof(struct command_struct);

    if (decrypt_command(ctx, command_data, &data_length) != 0) {
        // Log error, command decryption failed
        return -1;
    }

    execute_command(ctx, cmd->command_code, command_data, data_length);

    return 0;
}