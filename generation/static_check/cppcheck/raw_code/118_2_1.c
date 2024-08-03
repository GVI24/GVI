#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void secure_delete(const char *filename) {
    // Vulnerability: A race condition can occur here
    if (unlink(filename) == -1) {
        perror("unlink");
    } else {
        int fd = open(filename, O_CREAT | O_WRONLY, 0666);
        if (fd == -1) {
            perror("open");
            exit(1);
        }
        // Perform some operations with the file
        write(fd, "Erased", 6);
        close(fd);
    }
}

int main() {
    secure_delete("sensitive_data.txt");
    return 0;
}