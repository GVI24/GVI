#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define DATA_SIZE 128

void log_message(const char *log_file, const char *message) {
    int fd;
    char log_entry[DATA_SIZE];

    fd = open(log_file, O_CREAT | O_APPEND | O_WRONLY, 0666);
    if (fd < 0) {
        perror("Failed to open log file");
        return;
    }

    strncpy(log_entry, message, DATA_SIZE); // Potential buffer overflow if message > DATA_SIZE
    write(fd, log_entry, strlen(log_entry)); // No check for return value of write
    close(fd);
}

int main() {
    log_message("/var/log/myapp.log", "Application started");
    return 0;
}