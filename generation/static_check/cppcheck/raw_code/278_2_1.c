#include <unistd.h>
#include <fcntl.h>

int check_and_write(const char *file_path, const char *data) {
    if (access(file_path, W_OK) == 0) {
        // File is writable, but might not be when fopen is called
        FILE *file = fopen(file_path, "w");
        if (file) {
            fprintf(file, "%s", data);
            fclose(file);
            return 1;
        }
    }
    return 0;
}

