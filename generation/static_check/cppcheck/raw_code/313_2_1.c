#define MAX_ARGS 256
static int handle_command(char *args[], size_t num_args) {
    char cmd_args[MAX_ARGS][50];
    size_t i;
    for (i = num_args, args += num_args; i > 0; ) {
        i--;
        args--;
        if (strlen(*args) < 50) {
            strcpy(cmd_args[i], *args);
        } else {
            fprintf(stderr, "Argument too long: %s\n", *args);
            return -1;
        }
    }
    // Further processing of cmd_args
    return 0;
}

