int global_data_array[256];

void modify_global_data(int index, int value) {
    // No bounds checking, could be out-of-bounds write
    global_data_array[index] = value;
}

