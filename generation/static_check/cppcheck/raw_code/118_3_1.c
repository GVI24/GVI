#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/myfifo"

void setup_fifo() {
    int fd;
    
    // Vulnerability: A race condition can occur here
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }
    
    fd = open(FIFO_PATH, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    
    // Perform operations with the FIFO
    close(fd);
    
    // Cleanup
    unlink(FIFO_PATH);
}

int main() {
    setup_fifo();
    return 0;
}