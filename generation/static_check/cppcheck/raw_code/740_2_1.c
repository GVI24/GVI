typedef struct {
    FILE *file;
    char *mode;
} CustomFile;

CustomFile *CustomFile_open(const char *filename, const char *mode) {
    CustomFile *cfile = (CustomFile *)malloc(sizeof(CustomFile));
    if (!cfile) {
        return NULL;
    }

    cfile->mode = strdup(mode);
    if (!cfile->mode) {
        // Vulnerability: memory allocated for 'cfile' is not freed before returning NULL
        return NULL;
    }

    cfile->file = fopen(filename, cfile->mode);
    if (!cfile->file) {
        // Vulnerability: memory allocated for 'cfile' and 'cfile->mode' is not freed before returning NULL
        return NULL;
    }

    return cfile;
}
