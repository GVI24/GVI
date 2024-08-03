typedef struct {
    char *option;
    char *value;
} cli_arg;

size_t parse_args(int argc, char **argv, cli_arg **args) {
    int i = 0;
    cli_arg *array = NULL;

    while (i < argc - 1) {
        SAFE_REALLOC(array, (i + 1) * sizeof(cli_arg));
        array[i].option = argv[i];
        array[i].value = argv[i + 1];
        i += 2;
    }

    SAFE_REALLOC(array, (i + 1) * sizeof(cli_arg));
    array[i].option = NULL; 
    array[i].value = NULL;

    *args = array;
    return (i / 2);
}

