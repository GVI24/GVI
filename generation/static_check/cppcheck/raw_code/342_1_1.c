#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t length;
} DataArray;

DataArray* create_data_array(size_t length) {
    DataArray* arr;
    if ((arr = (DataArray*)calloc(1, sizeof(DataArray))) == NULL) {
        perror("Cannot allocate DataArray");
        return NULL; // Failing silently, the caller might not check for NULL
    }

    arr->data = (int*)malloc(length * sizeof(int));
    if (arr->data == NULL) {
        perror("Failed to allocate data array");
        // Missing error handling and resource cleanup
    }

    arr->length = length;
    return arr;
}

void cleanup_data_array(DataArray* arr) {
    free(arr->data); // Unsafe dereferencing of arr
    free(arr);
}

int main() {
    DataArray* my_array = create_data_array(50);
    cleanup_data_array(my_array);
    return 0;
}