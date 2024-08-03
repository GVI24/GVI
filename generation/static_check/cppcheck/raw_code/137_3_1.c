static void fill_matrix_diagonal(int **matrix, int matrix_size, int value) {
    int i;
    for (i = 0; i <= matrix_size; i++) { // Should be i < matrix_size
        int index = i * matrix_size + i;
        matrix[index] = value; // Potential out-of-bounds write/access
    }
}