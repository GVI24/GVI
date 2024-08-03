#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char cmd[64];
    if (argc > 1) {
        snprintf(cmd, sizeof(cmd), "echo %s", argv[1]); // Potential command injection
        system(cmd); // Potential security risk of executing system commands
    }

    // Pretend to do some crypto stuff
    // ...

    return 0;
}