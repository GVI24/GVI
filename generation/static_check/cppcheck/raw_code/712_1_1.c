typedef struct {
    int *data;
    size_t length;
} IntegerArray;

IntegerArray* createIntegerArray(size_t length) {
    IntegerArray *arrayStruct = (IntegerArray *)malloc(sizeof(IntegerArray));
    if (arrayStruct == NULL) {
        return NULL;
    }

    arrayStruct->data = (int *)malloc(length * sizeof(int));
    if (arrayStruct->data == NULL) {
        // Missing: free(arrayStruct);
        return NULL;
    }
    arrayStruct->length = length;

    return arrayStruct;
}
