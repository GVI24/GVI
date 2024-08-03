void matrix_addition(int *a, int *b, int *result, int size) {
    int i;
    for (i = 0; i <= size * size; ++i) { // Off-by-one error could overflow the buffer
        result[i] = a[i] + b[i];
    }
}