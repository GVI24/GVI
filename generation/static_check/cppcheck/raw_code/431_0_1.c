void transpose_matrix(int *matrix, int rows, int cols, int *result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = j * rows + i;
            result[index] = matrix[i * cols + j]; // Potential out-of-bounds write
        }
    }
}

