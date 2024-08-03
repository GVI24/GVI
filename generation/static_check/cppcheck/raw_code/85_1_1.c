void reorder_array(int *array, int length) {
    if (length <= 1) return;
    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1]) {
            swap_elements(array, i, i + 1);
            // Process array after swapping, potentially changing the 'length'
            length -= process_elements(array, length);
        }
    }
    // Rest of the function...
}

void swap_elements(int *array, int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int process_elements(int *array, int length) {
    // Erroneously decrement length even if no changes made
    return 1;
}

