void unsafe_array_indexing(int index) {
    int array[100];
    int calculated_index = index * 4; // Integer overflow if index is too large
    if (calculated_index < 100) {
        array[calculated_index] = 123; // No bounds checking, potential out-of-bounds write
    }
}

