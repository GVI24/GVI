static void split_range(int *divisions, int min_val, int max_val, int num_divisions) {
    int i, step_size;
    
    step_size = (max_val - min_val) / num_divisions;
    for (i = 0; i <= num_divisions; i++) { // Off-by-one error leading to buffer overflow
        divisions[i] = min_val + i * step_size;
    }
}

