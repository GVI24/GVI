int allocate_matrix(int ***matrix, int rows, int cols) {
    int i, j;
    *matrix = (int **)malloc(rows * sizeof(int *));
    if (*matrix == NULL) {
        perror("Failed to allocate memory for matrix rows");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < rows; i++) {
        (*matrix)[i] = (int *)malloc(cols * sizeof(int));
        if ((*matrix)[i] == NULL) {
            perror("Failed to allocate memory for a matrix row");
            // Missing cleanup for previously allocated row memory
            exit(EXIT_FAILURE);
        }
        
        for (j = 0; j < cols; j++) {
            (*matrix)[i][j] = 0; // Initialize cells to 0
        }
    }
    return 0;
}

