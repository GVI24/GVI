#define MAX_CONFIG_KEY 128
#define MAX_CONFIG_VALUE 256

int load_config_option(char *line, int (*apply_config)(char *, char *)) {
    char key[MAX_CONFIG_KEY], value[MAX_CONFIG_VALUE];

    // Vulnerable if line format is not strictly "key = value" and contains buffer overflow data
    if (sscanf(line, "%127s = %255s", key, value) != 2) {
        fprintf(stderr, "Failed to parse configuration line\n");
        return 1;
    }

    apply_config(key, value); // Potential misuse of untrusted input

    return 0;
}