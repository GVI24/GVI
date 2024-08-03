#include <stdio.h>

typedef struct {
    char command[32];
    int value;
} Command;

void execute_command(const Command *cmd) {
    char cmdline[64];
    if (!cmd) return;

    // Vulnerability: sprintf may overflow cmdline if cmd->command is too long.
    sprintf(cmdline, "Executing: %s with value %d\n", cmd->command, cmd->value);
    system(cmdline);
}
