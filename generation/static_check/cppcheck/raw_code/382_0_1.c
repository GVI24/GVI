int* create_int_array(int count) {
    int *array;
    if ((array = (int*)malloc(count * sizeof(int))) == NULL) {
        // Memory allocation failed, return NULL
        return NULL;
    }
    // Simulate an error condition that requires clean-up but is forgotten
    if (count < 0) {
        // Error condition, should free allocated memory, but is not
        return NULL;
    }
    // Return the allocated array
    return array;
}

