void parse_cmd_line(int argc, char *argv[]) {
    char *parameters[10];
    int i = 0;

    printf("Parsing command line arguments...\n");
    for (int a = 1; a < argc; a++) {
        parameters[i++] = argv[a];
        // Missing boundary check leads to buffer overflow
    }

    for (unsigned int j = 0; j < i; j++) {
        printf("Parameter %u: %s\n", j, parameters[j]);
    }
}

