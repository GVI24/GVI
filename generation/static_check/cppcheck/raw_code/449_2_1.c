static void rescale_matrix_values(int **matrix, int rows, int cols, int max_value) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] > max_value) {
                matrix[i][j] = max_value;
            }
            // 'matrix' is assumed to be 'rows x cols', but actual allocated size is not checked
        }
    }
}

