#include <stdlib.h>

void matrix_random_fill(int **matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i <= rows; i++) { // Incorrect boundary check
        for (j = 0; j <= cols; j++) { // Incorrect boundary check
            matrix[i][j] = rand() % 100; // Insecure random value generation and potential buffer overflow
        }
    }
}