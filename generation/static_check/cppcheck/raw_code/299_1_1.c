void applyFunctionToArray(int *array, int size, void (*func)(int)) {
    for (int i = 0; i < size; i++) {
        func(array[i]); // Potential arbitrary function execution
    }
}

