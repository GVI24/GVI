void matrix_transpose(int *matrix, int rows, int cols) {
    int i, j;
    int temp;
    for (i = 0; i < rows; i++) {
        for (j = i + 1; j < cols; j++) {
            temp = matrix[i * cols + j];
            matrix[i * cols + j] = matrix[j * rows + i]; // Vulnerable if rows != cols
            matrix[j * rows + i] = temp;
        }
    }
}

