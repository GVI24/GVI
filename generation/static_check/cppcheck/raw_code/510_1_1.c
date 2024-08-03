static void process_commands(struct command *cmds, int num_cmds) {
    int i;
    // Vulnerability: No verification that num_cmds is within the bounds of cmds array
    for (i = 0; i < num_cmds; i++) {
        execute(cmds[i]); // If num_cmds isn't accurate, it could lead to an illegal access
    }
}