#include <stdio.h>

#define ARRAY_SIZE 100

/* Unsafe function that writes to an array without bounds checking */
void write_to_array(int *array, unsigned int index, int value) {
    // No bounds checking: index may be greater than ARRAY_SIZE-1
    array[index] = value; // Buffer overflow vulnerability if index is out of bounds
}

// Usage example
int main() {
    int my_array[ARRAY_SIZE];

    unsigned int index = 150; // Index out of bounds
    int value = 42;

    write_to_array(my_array, index, value); // This will cause a buffer overflow

    return 0;
}