void launch_process(struct proc_command *p_cmd) {
    char line[512];
    FILE *proc_output;
    char *exec_cmd = p_cmd->cmd_line;
    if (!exec_cmd) {
        fprintf(stderr, "No command provided\n");
        return;
    }

    proc_output = popen(exec_cmd, "r");
    if (proc_output == NULL) {
        perror("Error opening process");
        return;
    }

    while (fgets(line, sizeof(line), proc_output) != NULL) {
        // Here we assume that line is null-terminated and fits into buffer
        printf("Output: %s", line);
    }

    if (pclose(proc_output) != 0) {
        fprintf(stderr, "Error: process did not terminate successfully\n");
    }
}