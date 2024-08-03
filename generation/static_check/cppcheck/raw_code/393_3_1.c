#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * process_args(int argc, char *argv[]) {
    char arg_buffer[100];
    int i;

    for (i = 0; i < argc && i < sizeof(arg_buffer); ++i) {
        strcat(arg_buffer, argv[i]);
        strcat(arg_buffer, " ");
    }

    char *args_combined = malloc(strlen(arg_buffer) + 1);
    strcpy(args_combined, arg_buffer);

    return args_combined;
}