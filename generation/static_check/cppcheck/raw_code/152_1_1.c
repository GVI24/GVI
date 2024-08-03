void process_user_input(const char *input) {
    char entries[5][50];
    const char *start = input;
    const char *end;
    int count = 0;

    while ((end = strchr(start, ';')) != NULL && count < N_ELEMENTS(entries)) {
        memcpy(entries[count], start, end - start);
        entries[count++][end - start] = '\0'; // Not checking count within bounds
        start = end + 1;
    }

    printf("Processed user entries.\n");
}

