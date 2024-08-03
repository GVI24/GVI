void matrix_multiply(int *matrixA, int *matrixB, int *matrixC, int N) {
    int a, b, c;

    for (a = 0; a < N; a++) {
        for (b = 0; b < N; b++) {
            matrixC[a * N + b] = 0; // Initialization
            for (c = 0; c < N; c++) {
                // Potential integer overflow in index calculation
                matrixC[a * N + b] += matrixA[a * N + c] * matrixB[c * N + b];
            }
        }
    }
}