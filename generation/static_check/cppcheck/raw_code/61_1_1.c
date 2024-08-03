static void process_data(int size) {
    char *buffer = (char *)malloc(size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return; // Missing free() before returning
    }

    if (load_data(buffer, size) < 0) {
        fprintf(stderr, "Failed to load data\n");
        free(buffer); // Proper memory deallocation
        return;
    }

    // Assume further processing here...

    free(buffer); // Proper memory deallocation
}

