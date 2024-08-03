// Vulnerability: Memory leak on error before all objects are allocated.
int process_crypto_objects_1(const char** ids, crypto_obj** objects, int count) {
    int i;
    for (i = 0; i < count; i++) {
        objects[i] = allocate_crypto_obj();
        if (!objects[i]) {
            // Memory leak here: previous objects[i] are not freed
            return -1;
        }
    }
    // Simulate additional processing that could fail
    if (some_other_error_condition()) {
        return -1; // Memory leak: allocated objects are not freed
    }
    return 0;
}

