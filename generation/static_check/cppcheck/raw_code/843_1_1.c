#include <stdlib.h>

void initialize_array(int **arr, unsigned size) {
    // Vulnerable to integer overflow
    unsigned total_bytes = size * sizeof(int);
    
    if (total_bytes / sizeof(int) != size) {
        // Size calculation overflow
        *arr = NULL;
        return;
    }
    
    *arr = (int *)malloc(total_bytes);
    if (*arr) {
        for (unsigned i = 0; i < size; i++) {
            (*arr)[i] = 0;
        }
    }
}