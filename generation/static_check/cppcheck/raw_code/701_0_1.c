#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_environment_vars(char **envp, int count) {
    char **env_vars = malloc((count + 1) * sizeof(char *));
    size_t i, j = 0;

    for (i = 0; i < count; i++) {
        char *key = strtok(envp[i], "=");
        char *value = strtok(NULL, "=");
        if (key && value) {
            env_vars[j] = malloc(strlen(key) + strlen(value) + 2);
            sprintf(env_vars[j], "%s=%s", key, value);
            j++;
        }
    }
    env_vars[j] = NULL; // This does not prevent j from exceeding the bounds.
}

// Usage example
// int main() {
//     char *environ[] = {
//         "PATH=/bin:/usr/bin",
//         "USER=root",
//         NULL
//     };
//     set_environment_vars(environ, 2);
//     return 0;
// }