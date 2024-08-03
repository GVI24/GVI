#include <stdlib.h>
#include <stdio.h>

#define SMALL_BUFFER 64

void append_data(const char *data) {
    char local_buf[SMALL_BUFFER];
    int required_size = strlen(data) + 1;
    
    if (required_size > SMALL_BUFFER) {
        printf("Buffer overflow detected! Aborting.\n");
        abort();
    }
    
    strcpy(local_buf, data); // Copy without size check
    // More operations on local_buf
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        append_data(argv[1]);
    }
    return 0;
}