// Vulnerability: Memory leak within loop condition.
int process_crypto_objects_4(const char** ids, crypto_obj** objects, int count) {
    int i, err = 0;
    for (i = 0; i < count && !err; i++) {
        objects[i] = allocate_crypto_obj();
        if (!objects[i]) {
            err = -1;
        } else if (i > 0 && special_operation_failed(objects[i], objects[i - 1])) {
            // Memory leak: early loop exit without releasing objects[i]
            err = -1;
        }
    }
    if (err) {
        for (i = 0; i < count; i++) {
            if (objects[i]) {
                release_crypto_obj(objects[i]);
            }
        }
        return err;
    }
    return 0;
}