#define MAX_BUFFER_SIZE 2048

typedef void (*CommandHandler)(const char*);

typedef struct {
    char command[MAX_BUFFER_SIZE];
    CommandHandler handler;
} CommandEntry;

CommandEntry command_table[] = {
    {"start", start_service},
    {"stop", stop_service},
    {"restart", restart_service},
    {"", NULL}
};

CommandEntry* find_command_entry(char *command_string) {
    for (int i = 0; command_table[i].handler; i++) {
        if (strncmp(command_table[i].command, command_string, strlen(command_string)) == 0) {
            // No bounds check for command_string, leading to possible out-of-bounds read
            return &command_table[i];
        }
    }
    return NULL;
}