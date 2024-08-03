typedef void (*event_callback)(int);

int setup_event_handler(event_callback **event_table, int event_code, event_callback handler) {
    int table_size = 100; // Arbitrary table size
    if (event_code >= table_size) {
        fprintf(stderr, "Event code exceeds table size\n");
        return -1;
    }

    if (event_table[event_code] != NULL) {
        // Memory leak: the existing handler is not freed before overwriting
    }

    event_table[event_code] = malloc(sizeof(handler));
    if (event_table[event_code] == NULL) {
        perror("Failed to allocate memory for event handler");
        return -1; // Memory allocation error
    }

    *event_table[event_code] = handler;
    return 0;
}