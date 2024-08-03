void load_config_file(const char *filename, config_tree *config) {
    FILE *config_file = fopen(filename, "r");
    char line[1024];
    
    // Vulnerability: Assuming fopen always succeeds without checking for NULL
    while (fgets(line, sizeof(line), config_file) != NULL) {
        parse_line(line, config);
    }
    fclose(config_file);
    // Other file loading code...
}

