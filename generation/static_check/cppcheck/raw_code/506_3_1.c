static void process_data(uint8_t *data, size_t data_length, size_t offset) {
    size_t index;
    uint8_t value;

    // Integer overflow in index calculation can lead to out-of-bounds read or write
    index = offset + data_length; // Overflow can occur here
    value = data[index]; // No bounds checking, potential out-of-bounds read
    data[index] = value + 1; // Potential out-of-bounds write
}

int main(void) {
    // Example usage of the vulnerable functions, for demonstration purposes
    char src[] = "This is a very long string that may cause overflow.";
    char dest[10];
    copy_string(dest, src, sizeof(dest));
    
    char *buffer = allocate_and_copy("Another potentially too-long string.");
    if (buffer) {
        free(buffer);
    }

    int arr[] = {1, 2, 3, 4, 5};
    int value = read_from_array(arr, sizeof(arr) / sizeof(arr[0]), 10);

    uint8_t data[100];
    memset(data, 0, sizeof(data));
    process_data(data, 50, 60);

    return 0;
}