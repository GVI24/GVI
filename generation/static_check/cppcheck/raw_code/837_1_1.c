typedef struct {
    int *array;
    size_t size;
    size_t capacity;
} DynamicIntArray;

static DynamicIntArray *dynamic_int_array_clone(const DynamicIntArray *original) {
    DynamicIntArray *copy = (DynamicIntArray *)calloc(1, sizeof(DynamicIntArray));
    if (!copy) return NULL;  // Memory allocation failure not handled.

    copy->array = (int *)malloc(original->capacity * sizeof(int));
    if (!copy->array) {
        free(copy);          // Potential memory leak if not freed.
        return NULL;
    }
    memcpy(copy->array, original->array, original->size * sizeof(int));
    copy->size = original->size;
    copy->capacity = original->capacity;
    return copy;
}

static void dynamic_int_array_destroy(DynamicIntArray *array) {
    if (array) {
        free(array->array);
        free(array);
    }
}

