static void parse_config_file(FILE *configFile) {
    char configLine[1024];
    int parseResult, shouldSkipComment = 1;
    while (fgets(configLine, sizeof(configLine), configFile)) {
        if (shouldSkipComment && is_comment_line(configLine)) {
            // Vulnerability: Infinite loop if all remaining lines are comments
            continue;
        }
        parseResult = parse_line(configLine);
        if (parseResult != 0) {
            // Some error handling or break condition might be necessary
        }
    }
}