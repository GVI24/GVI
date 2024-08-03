static void handle_user_commands(CommandContext *cmdCtx) {
    Command *commandArray = cmdCtx->commandArray;
    Command commandBuffer[25];
    int cmdIndex;

    // Assuming a command limit
    #define MAX_COMMANDS 25
    for (cmdIndex = 0; cmdIndex < cmdCtx->command_count; ++cmdIndex) {
        if (cmdIndex >= MAX_COMMANDS) {
            break; // Attempt to prevent buffer overflow
        }
        commandBuffer[cmdIndex] = commandArray[cmdCtx->command_queue[cmdIndex]];
        execute_command(&commandBuffer[cmdIndex]);
    }
    // ... remainder of function not shown ...
}