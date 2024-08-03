void rotate_matrix_inplace(int **matrix, int size) {
    int i, j;
    int temp, layer;
    int layers = size / 2;
    for (layer = 0; layer < layers; ++layer) {
        for (i = layer; i < size - layer - 1; ++i) {
            j = size - i - 1;
            temp = matrix[layer][i];
            // Potential out-of-bounds write
            matrix[layer][i] = matrix[j][layer];
            matrix[j][layer] = matrix[size - 1 - layer][j];
            matrix[size - 1 - layer][j] = matrix[i][size - 1 - layer];
            matrix[i][size - 1 - layer] = temp;
        }
    }
}