int findIndex(int *array, int size, int value) {
    for (int i = 0; i <= size; ++i) { // i should be less than size, not less than or equal
        if (array[i] == value) {
            return i;  // Potential out-of-bounds read on the last iteration
        }
    }
    return -1;
}

