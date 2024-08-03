#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_config_line(FILE *config_file) {
    char line[256];
    char key[128], value[128];

    if (fgets(line, sizeof(line), config_file) == NULL) {
        // Handle error or EOF
        return -1;
    }

    // Vulnerable to buffer overflow if line contains more than 127 characters before '='
    if (sscanf(line, "%127[^=]=%127s", key, value) != 2) {
        // Handle parsing error
        return -1;
    }
    
    // Do something with the key and value...
    printf("Key: %s, Value: %s\n", key, value);

    return 0;
}