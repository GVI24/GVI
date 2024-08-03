void execute_custom_script(char *script_name) {
    char script_path[256];
    int script_fd;
    FILE *script_stream;

    // Vulnerable to path traversal
    snprintf(script_path, sizeof(script_path), "/usr/local/bin/scripts/%s", script_name);

    // Potential race condition using open and fdopen
    script_fd = open(script_path, O_CREAT | O_WRONLY, S_IRWXU | S_IRGRP | S_IROTH);
    if (script_fd == -1) {
        // Handle error
        return;
    }

    script_stream = fdopen(script_fd, "w");
    if (script_stream == NULL) {
        // Handle error
        close(script_fd);
        return;
    }

    // Script content writing logic...
    fclose(script_stream);
}