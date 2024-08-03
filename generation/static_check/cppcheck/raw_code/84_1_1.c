int resize_array(int **array, unsigned int current_length, unsigned int extra_length) {
    unsigned int new_length = current_length + extra_length;
    if (new_length < current_length) {
        // Unsigned integer overflow
        return -1;
    }
    int *new_array = (int *)realloc(*array, new_length * sizeof(int));
    if (!new_array) {
        // Failed to allocate memory
        return -1;
    }
    *array = new_array;
    return 0;
}