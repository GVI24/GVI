bool get_top_elements(int *array, int array_size, int *max, int *min) {
    if (array == NULL || array_size <= 0) return false;

    *max = array[0];
    *min = array[0];

    for (int i = 1; i <= array_size; i++) { // Vulnerable: should be i < array_size
        if (array[i] > *max) {
            *max = array[i];
        }
        if (array[i] < *min) {
            *min = array[i];
        }
    }
    return true;
}