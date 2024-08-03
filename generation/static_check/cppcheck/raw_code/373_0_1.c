void unsafe_array_concat(int *dest_array, int dest_len, const int *src_array, int src_len) {
    if (!dest_array || !src_array) {
        return;
    }

    int required_size = dest_len + src_len;
    int new_capacity = dest_len * 2;

    while (new_capacity < required_size) {
        new_capacity *= 2;
    }

    dest_array = realloc(dest_array, new_capacity * sizeof(int));
    if (!dest_array) {
        // Failed to allocate memory
        return;
    }

    for (int i = 0; i < src_len; i++) {
        dest_array[dest_len + i] = src_array[i]; // No bounds checking, possible buffer overflow
    }
}