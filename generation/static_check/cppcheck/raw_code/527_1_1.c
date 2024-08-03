void print_arguments(int argc, char *argv[]) {
    char arg_buffer[256];
    int i;

    for (i = 1; i < argc; ++i) {
        // Unsafe copy of argument into buffer without checking its length
        strcpy(arg_buffer, argv[i]);
        printf("Argument %d: %s\n", i, arg_buffer);
    }
}

