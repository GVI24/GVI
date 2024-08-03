void resize_array(int **array, int current_size, int new_size) {
    assert(array && *array); // Assert used instead of proper error handling
    int *temp = realloc(*array, new_size * sizeof(int));
    assert(temp); // Unsafe use of assert for checking realloc result
    memset(temp + current_size, 0, (new_size - current_size) * sizeof(int)); // Potential NULL pointer dereference if realloc fails
    *array = temp;
}

