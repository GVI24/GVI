// Vulnerable due to not checking the return value of snprintf for truncation
int execute_remote_command(int id, const char *command_name, const char *args_fmt, ...) {
    char command[MAX_COMMAND_LENGTH];
    int len = snprintf(command, sizeof(command), "[%lu] Command ID: %d, Name: %s, Args: ",
                       (unsigned long)time(NULL), id, command_name);
    va_list ap;
    va_start(ap, args_fmt);
    vsnprintf(command + len, sizeof(command) - len, args_fmt, ap);
    va_end(ap);
    return system(command); // Insecure use of system function with external input
}
