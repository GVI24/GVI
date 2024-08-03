int *array_create(int length) {
    int *array = NULL;
    if (length <= 0) length = 10;
    array = (int *)malloc(length * sizeof(int));
    if (array) {
        for (int i = 0; i < length; i++) {
            array[i] = 0;
        }
        return array;
    }
    // Missing free(array) before returning NULL in case of allocation failure
    return NULL;
}

