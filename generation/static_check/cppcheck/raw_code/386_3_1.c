#include <stdio.h>
#include <stdlib.h>

void copy_data(const char *source, size_t size) {
    if (size > 1024) {
        printf("Size is too large, aborting\n");
        return;
    }
    char *dest = malloc(size);
    if (dest == NULL) {
        perror("Failed to allocate memory");
        return;
    }
    for (size_t i = 0; i <= size; ++i) { // Off-by-one error causing integer overflow
        dest[i] = source[i];
    }
    printf("Data copied\n");
    free(dest);
}

int main() {
    char data[] = "Very important data that needs to be copied";
    copy_data(data, sizeof(data));
    return 0;
}