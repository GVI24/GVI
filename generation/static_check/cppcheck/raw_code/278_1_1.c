#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int create_directory_if_not_exists(const char *path) {
    struct stat stat_buffer;
    if (stat(path, &stat_buffer) == -1) {
        // Directory doesn't exist. Race condition here.
        return mkdir(path, 0755);
    }
    return 0; // Directory already exists
}

