int** init_matrix(int rows, int cols) {
    int i;
    int **matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        // Memory allocation failed for matrix, return NULL
        return NULL;
    }
    for (i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            // Memory allocation failed for a row, previous rows are not freed
            return NULL;
        }
    }
    return matrix;
}

