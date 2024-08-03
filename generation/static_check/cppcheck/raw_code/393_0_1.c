#include <stdio.h>
#include <stdlib.h>

char * unsafe_copy_from_file(const char *filename) {
    FILE *fp;
    char buffer[256];
    int index = 0;
    char ch;

    fp = fopen(filename, "r");
    if (fp == NULL) return NULL;

    while ((ch = fgetc(fp)) != EOF && index < sizeof(buffer)) {
        buffer[index++] = ch;
    }
    buffer[index] = '\0';

    char *result = (char *)malloc(strlen(buffer) + 1);
    strcpy(result, buffer);
    fclose(fp);

    return result;
}