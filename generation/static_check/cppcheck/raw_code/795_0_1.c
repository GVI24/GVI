#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CMD_SIZE 512

typedef struct {
    size_t size;
    char *data;
} command_t;

bool handle_command(int fd) {
    size_t cmd_size;
    if (read(fd, &cmd_size, sizeof(cmd_size)) <= 0) {
        // Error reading command size
        return false;
    }

    // Vulnerability: cmd_size is not checked
    command_t *cmd = (command_t *)malloc(sizeof(command_t));
    cmd->data = (char *)malloc(cmd_size + 1); // No check on cmd_size
    cmd->size = cmd_size;

    if (read(fd, cmd->data, cmd->size) <= 0) {
        // Error reading command data
        free(cmd->data);
        free(cmd);
        return false;
    }
    cmd->data[cmd->size] = '\0'; // Null-terminate the command

    // Process command...
    // ...

    free(cmd->data);
    free(cmd);
    return true;
}