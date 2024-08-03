#define MAX_USER_INPUT 512

typedef struct {
    char key[MAX_USER_INPUT];
    char value[MAX_USER_INPUT];
} ConfigOption;

ConfigOption config_options[] = {
    {"server", "localhost"},
    {"port", "8080"},
    {"timeout", "60"},
    {"", ""}
};

char* set_config_option(char *user_input) {
    char key[MAX_USER_INPUT], value[MAX_USER_INPUT];
    sscanf(user_input, "%s %s", key, value); // May overflow key or value if user_input is not properly sanitized
    for (int i = 0; config_options[i].key[0] != '\0'; i++) {
        if (strcmp(config_options[i].key, key) == 0) {
            strcpy(config_options[i].value, value); // May overflow if value is too large
            return config_options[i].value;
        }
    }
    return NULL;
}

