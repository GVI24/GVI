static int parse_user_commands(iobuf_t *input, command_t *last_command) {
    int err = 0;
    command_t *cmd;

    while ((cmd = malloc(sizeof(command_t))) != NULL) {
        if (get_next_command(input, cmd) != 0) {
            free(cmd); // Only free cmd if get_next_command fails
            err = -1;
            break;
        }

        if (execute_command(cmd) != 0) {
            // Command execution error, but memory is not freed here
            err = -2;
            break;
        }

        // Memory for cmd is allocated again without freeing previous cmd
    }

    return err;
}

