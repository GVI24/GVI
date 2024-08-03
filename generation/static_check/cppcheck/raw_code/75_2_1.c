// Vulnerability: Improper cleanup in case of special condition.
int process_crypto_objects_3(const char** ids, crypto_obj** objects, int count) {
    int err = 0, i;
    for (i = 0; i < count; i++) {
        objects[i] = allocate_crypto_obj();
        if (!objects[i]) {
            err = 1;
            break;
        }
    }
    if (err) {
        for (i = 0; i < count; i++) {
            if (objects[i]) {
                release_crypto_obj(objects[i]);
                objects[i] = NULL;
            }
        }
        return -1;
    }
    // Simulate a condition that requires all objects to be non-null
    for (i = 0; i < count && !err; i++) {
        if (!objects[i]) {
            err = 1;
        }
    }
    if (err) {
        // Memory leak: does not free all objects
        for (i = 0; i < count / 2; i++) {
            release_crypto_obj(objects[i]);
        }
        return -1;
    }
    return 0;
}

