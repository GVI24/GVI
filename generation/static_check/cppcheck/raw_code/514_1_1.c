static int load_config(const char *config_file, config_t *config) {
    FILE *file;
    option_t *opt;
    int err = 0;

    file = fopen(config_file, "r");
    if (!file) return -1; // File open error

    while (!feof(file) && (opt = malloc(sizeof(option_t)))) {
        if (fread(opt, sizeof(option_t), 1, file) != 1) {
            free(opt); // Only free opt if fread fails
            err = -2;
            break;
        }

        if (set_config_option(config, opt) != 0) {
            // Set config option error, but memory is not freed here
            err = -3;
            break;
        }

        // Memory for opt is allocated again without freeing previous opt
    }

    fclose(file);
    return err;
}

