#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void process_temp_file() {
    char *tmp_file = "/tmp/myapp.tmp";
    int fd;
    
    // Vulnerability: A race condition can occur here
    if (access(tmp_file, F_OK) == -1) {
        fd = open(tmp_file, O_CREAT | O_WRONLY, 0666);
        if (fd == -1) {
            perror("open");
            exit(1);
        }
        // Write some data to the file
        write(fd, "temporary data", 14);
        close(fd);
    } else {
        fprintf(stderr, "Temp file already exists\n");
    }
}

int main() {
    process_temp_file();
    return 0;
}