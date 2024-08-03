typedef struct {
    int *numbers;
    size_t count;
} NumberArray;

NumberArray *create_number_array(size_t count) {
    NumberArray *array = (NumberArray *)malloc(sizeof(NumberArray));
    if (!array) {
        return NULL;
    }
    
    array->numbers = (int *)calloc(count, sizeof(int));
    if (!array->numbers) {
        free(array);
        return NULL;
    }
    
    // Missing initialization error handling
    array->count = count;
    return array;
}