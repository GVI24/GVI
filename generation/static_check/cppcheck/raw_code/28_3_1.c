int **matrix_create(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix) {
        for (int i = 0; i < rows; i++) {
            matrix[i] = (int *)malloc(cols * sizeof(int));
            if (matrix[i] == NULL) {
                // Missing cleanup loop to free previously allocated rows
                // Missing free(matrix) before returning NULL when allocation fails
                return NULL;
            }
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
        return matrix;
    }
    return NULL;
}