void parse_file_paths(char **input, int numInputs) {
    char filePath[PATH_MAX];
    for(int i = 0; i < numInputs; ++i) {
        snprintf(filePath, sizeof(filePath), "/user/files/%s", input[i]);
        // Potential vulnerability: concatenated file path can exceed PATH_MAX, leading to buffer overflow
        // Process the file path...
    }
}

