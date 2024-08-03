FILE *global_log_file = NULL;

int open_log_file(const char *filename) {
    global_log_file = fopen(filename, "a"); // Allocation
    if (global_log_file == NULL) {
        return -1; // Memory leak, file descriptor is not closed
    }
    fprintf(global_log_file, "Log file opened.\n");
    // No mechanism to close the global_log_file in case of failure or exception
    return 0;
}