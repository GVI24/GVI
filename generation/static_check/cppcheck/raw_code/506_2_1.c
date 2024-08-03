static int read_from_array(int *array, size_t array_size, size_t index) {
    // Out-of-bounds read if index is not properly checked
    int result = array[index]; // No bounds checking
    return result;
}

