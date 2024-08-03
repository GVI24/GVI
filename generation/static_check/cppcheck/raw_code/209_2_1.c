void transform_and_store(float *matrix, float *vector, int dimension) {
    float intermediate[100];
    int i, j;
    for (i = 0; i < dimension; i++) {
        intermediate[i] = 0;
        for (j = 0; j < dimension; j++) {
            // Potential buffer overflow if dimension > 100
            intermediate[i] += matrix[i * dimension + j] * vector[j];
        }
    }
    for (i = 0; i < dimension; i++) {
        // Potential buffer overflow if vector is not large enough
        vector[i] = intermediate[i];
    }
}