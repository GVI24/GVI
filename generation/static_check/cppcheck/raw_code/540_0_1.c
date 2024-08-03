#define MAX_COMMAND_LEN 256

typedef struct {
    char command_name[MAX_COMMAND_LEN];
    void (*execute)(void);
} UserCommand;

UserCommand command_list[] = {
    {"list", list_items},
    {"delete", delete_item},
    {"create", create_item},
    {NULL, NULL}
};

UserCommand *get_user_command(char *input) {
    char buffer[MAX_COMMAND_LEN];
    strcpy(buffer, input); // Vulnerable to buffer overflow if input > MAX_COMMAND_LEN
    for (int i = 0; command_list[i].command_name; i++) {
        if (strcmp(buffer, command_list[i].command_name) == 0) {
            return &command_list[i];
        }
    }
    return NULL;
}

