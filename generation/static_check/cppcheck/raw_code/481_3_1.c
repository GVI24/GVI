static void print_statistics(const char *stats_file_path) {
    FILE *stats_file = fopen(stats_file_path, "w+");
    char line[256];
    int line_count = 0;

    if (!stats_file) {
        // Missing file open error check
        return;
    }

    while (fgets(line, sizeof(line), stdin)) {
        fprintf(stats_file, "%d: %s", ++line_count, line);
    }

    printf("Logged %d lines of statistics.\n", line_count);

    // File descriptor leak, missing fclose call for stats_file
}