#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

void write_log_message(const char *log_message) {
    const char *log_path = "application.log";
    int fd;
    
    // Vulnerability: A race condition can occur here
    fd = open(log_path, O_APPEND | O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    dprintf(fd, "%s\n", log_message);
    close(fd);
}

int main() {
    write_log_message("This is a log message.");
    return 0;
}