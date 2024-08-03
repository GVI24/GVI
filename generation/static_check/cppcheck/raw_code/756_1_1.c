typedef struct {
    int *data;
    int size;
} IntArray;

bool process_array(IntArray *arr_struct, int **result) {
    *result = (int *)malloc(arr_struct->size * sizeof(int));
    if (*result == NULL) return false;

    for (int i = 0; i < arr_struct->size; i++) {
        (*result)[i] = arr_struct->data[i] * 2;
        if (arr_struct->data[i] == 0) {
            // Vulnerable: Forgot to free 'result' on error path
            return false;
        }
    }
    return true;
}