typedef struct {
    FILE *file;
    int (*process_func)(FILE *);
} file_processor;

int file_processor_execute(file_processor *processor) {
    if (processor == NULL || processor->file == NULL) {
        return -1;
    }
    if (processor->process_func(processor->file) != 0) {
        return -1;
    }
    fclose(processor->file); // After this, processor->file is no longer valid
    // Potential Use-After-Free: accessing processor->file after it's been closed
    fseek(processor->file, 0L, SEEK_SET);
    return 0;
}

