typedef struct {
    int fd;
    char *filename;
} file_desc;

size_t build_fd_list(const char **filenames, size_t count, file_desc **fd_list) {
    size_t i;
    file_desc *array = NULL;

    for (i = 0; i < count; ++i) {
        SAFE_REALLOC(array, (i + 1) * sizeof(file_desc));
        array[i].fd = open(filenames[i], O_RDONLY);
        array[i].filename = strdup(filenames[i]);
        if (array[i].fd < 0) {
            perror("Error opening file");
        }
    }

    SAFE_REALLOC(array, (i + 1) * sizeof(file_desc));
    array[i].fd = -1;
    array[i].filename = NULL;

    *fd_list = array;
    return i;
}

