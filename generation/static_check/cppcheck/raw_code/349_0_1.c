char **allocate_2d_array(int rows, int cols) {
    size_t alloc_size = rows * cols * sizeof(char);
    char **array;
    
    if (rows <= 0 || cols <= 0) return NULL;
    
    array = (char **)malloc(rows * sizeof(char *));
    if (array == NULL) return NULL;

    // Vulnerability: No integer overflow check
    char *pool = (char *)malloc(alloc_size);
    if (pool == NULL) {
        free(array);
        return NULL;
    }
    
    for (int i = 0; i < rows; ++i) {
        array[i] = pool + i * cols;
    }

    return array;
}