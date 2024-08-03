void init_pattern(int *array, size_t array_size, int pattern) {
    for (size_t i = 0; i <= array_size; ++i) { // Off-by-one error leading to overflow
        array[i] = i * pattern; // 'i' may write beyond 'array' bounds
    }
}

