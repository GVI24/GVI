#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define MAX_RECORDS 10

int save_data(const char *filename) {
    int fd;
    char buffer[BUFFER_SIZE];
    int record_count = get_record_count(); // Assume this function is defined elsewhere

    fd = open(filename, O_CREAT|O_WRONLY, 0600);
    if (fd < 0) return -1;

    if (record_count > MAX_RECORDS) {
        close(fd);
        return -1;
    }

    for (int i = 0; i <= record_count; i++) {
        get_record(buffer, i); // Assume this function is defined elsewhere
        write(fd, buffer, strlen(buffer)); // No check for return value of write
    }

    close(fd);
    return 0;
}