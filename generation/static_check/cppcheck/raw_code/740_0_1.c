typedef struct {
    int *data;
    size_t size;
} IntArray;

IntArray *IntArray_create(size_t init_size) {
    IntArray *array = (IntArray *)malloc(sizeof(IntArray));
    if (!array) {
        return NULL;
    }

    array->data = (int *)malloc(init_size * sizeof(int));
    if (!array->data) {
        // Vulnerability: memory allocated for 'array' is not freed before returning NULL
        return NULL;
    }

    array->size = init_size;
    return array;
}
