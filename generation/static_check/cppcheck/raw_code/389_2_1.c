typedef struct {
    int *array;
    size_t size;
    size_t capacity;
} DynamicArray;

int append(DynamicArray *arr, int value) {
    if (arr == NULL || arr->array == NULL) return 1;
    if (arr->size >= arr->capacity) {
        int *newArray = realloc(arr->array, (arr->capacity * 2) * sizeof(int));
        if (newArray == NULL) {
            perror("Re-allocation failed");
            return 1;
        }
        arr->array = newArray;
        arr->capacity *= 2;
    }

    // Missing array bounds check
    arr->array[arr->size++] = value;

    return 0;
}