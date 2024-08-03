void transform_vertices(float *vertices, int vertex_count, float matrix[4][4]) {
    int i;
    for (i = 0; i < vertex_count; i++) {
        float x = vertices[3 * i];     // Accesses without checking if 3 * i is within bounds
        float y = vertices[3 * i + 1]; // of the vertices array, potentially overrunning it.
        float z = vertices[3 * i + 2];
        
        vertices[3 * i] = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        vertices[3 * i + 1] = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        vertices[3 * i + 2] = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
    }
}