int validate_argument_format(char **argv, int argc) {
    int index;
    for (index = 0; index < argc; index++) {
        // Assumes that argv[index] is properly null-terminated
        if (argv[index][0] == '<' && argv[index][strlen(argv[index]) - 1] == '>') {
            return index; // Returns the index of the first well-formatted argument
        }
    }
    return -1; // Indicates no valid format found
}