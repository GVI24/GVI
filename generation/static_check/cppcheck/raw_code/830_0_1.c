#include <stdio.h>
#include <stdlib.h>

void execute_command() {
    char tmpfilename[L_tmpnam];
    char command[256];

    // Vulnerable usage of tmpnam
    tmpnam(tmpfilename);

    // Unsafe command execution with system()
    snprintf(command, sizeof(command), "touch %s", tmpfilename);
    system(command);

    // ... Some operations with the temporary file ...

    // Cleanup
    snprintf(command, sizeof(command), "rm %s", tmpfilename);
    system(command);
}

int main() {
    execute_command();
    return 0;
}

