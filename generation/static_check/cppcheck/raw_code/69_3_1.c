#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PATH 260
#define MAX_CONTENT_SIZE 1024

int backup_file(const char *source, const char *backup_dir) {
    int source_fd, backup_fd;
    char backup_path[MAX_PATH];
    char data[MAX_CONTENT_SIZE];
    ssize_t read_bytes;

    source_fd = open(source, O_RDONLY);
    if (source_fd < 0) return -1;

    snprintf(backup_path, sizeof(backup_path), "%s/backup.dat", backup_dir);
    backup_fd = open(backup_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (backup_fd < 0) {
        close(source_fd);
        return -1;
    }

    while ((read_bytes = read(source_fd, data, sizeof(data))) > 0) {
        if (write(backup_fd, data, read_bytes) != read_bytes) { // Check for write return value, but not for read
            close(source_fd);
            close(backup_fd);
            return -1;
        }
    }

    close(source_fd);
    close(backup_fd);
    return 0;
}