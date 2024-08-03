int create_string_array(char ***array, int num_strings, int string_length) {
    int i;
    *array = (char **)malloc(num_strings * sizeof(char *));
    if (*array == NULL) {
        perror("Failed to allocate memory for string array");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < num_strings; i++) {
        (*array)[i] = (char *)malloc(string_length * sizeof(char));
        if ((*array)[i] == NULL) {
            perror("Failed to allocate memory for a string");
            // Missing cleanup for previously allocated string memory
            exit(EXIT_FAILURE);
        }
        (*array)[i][0] = '\0'; // Initialize string as empty
    }
    return 0;
}

