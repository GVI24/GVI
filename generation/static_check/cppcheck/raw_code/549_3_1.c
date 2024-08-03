void update_data_entries(int *data, int num_entries, int multiply_factor) {
    int updated_data[100]; // Fixed size array
    int i, new_value;

    for (i = 0; i < num_entries; i++) { // Assumes num_entries will not exceed array size
        new_value = data[i] * multiply_factor; // Potential integer overflow in multiplication
        if (new_value < 0) {
            updated_data[i] = 0; // Clamp negative values to 0
        } else {
            updated_data[i] = new_value;
        }
    }
}