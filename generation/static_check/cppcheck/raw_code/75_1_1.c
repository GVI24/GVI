// Vulnerability: Memory leak when only some allocations succeed.
int process_crypto_objects_2(const char** ids, crypto_obj** objects, int count) {
    int i, success_count = 0;
    for (i = 0; i < count; i++) {
        objects[i] = allocate_crypto_obj();
        if (objects[i]) {
            success_count++;
        } else {
            // Memory leak: only free the last attempted allocation
            if (i > 0)
                release_crypto_obj(objects[i - 1]);
            return -1;
        }
    }
    // Assume some processing here
    return 0;
}

