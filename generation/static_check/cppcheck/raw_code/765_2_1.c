void external_array_access(int *array, size_t size, int index, int value) {
    // No check is done to ensure 'index' is within the bounds of 'array'
    array[index] = value; // Potential out-of-bounds write
}

