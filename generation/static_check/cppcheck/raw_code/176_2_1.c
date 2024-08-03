void cleanupStringArray(char **array, int size) {
    for(int i = 0; i < size; ++i) {
        free(array[i]);  // Vulnerability: should set array[i] to NULL after free
        // array[i] is now a dangling pointer
    }
    free(array);  // Potential double free if array is not set to NULL and used again
    // array is now a dangling pointer
}

