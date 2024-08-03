int init_2d_array(int ***array, int rows, int columns) {
    int i;
    *array = (int **)malloc(rows * sizeof(int *));
    if (*array == NULL) {
        perror("Failed to allocate memory for 2D array rows");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < rows; i++) {
        (*array)[i] = (int *)malloc(columns * sizeof(int));
        if ((*array)[i] == NULL) {
            perror("Failed to allocate memory for 2D array columns");
            // Missing cleanup for previously allocated rows
            exit(EXIT_FAILURE);
        }

        // Initialize the array with some value, e.g., -1
        for (int j = 0; j < columns; j++) {
            (*array)[i][j] = -1;
        }
    }
    return 0;
}