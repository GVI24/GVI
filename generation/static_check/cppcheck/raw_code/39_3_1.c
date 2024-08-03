int read_and_duplicate(const char *filename, char **output) {
    FILE *file;
    long file_size;
    char *buffer;

    file = fopen(filename, "rb");
    if (!file) {
        // File opening failed with no error handling
        return -1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    buffer = (char *)malloc(file_size + 1);
    if (!buffer) {
        fclose(file); // Closing file but no error code for memory allocation failure
        return -1;
    }

    fread(buffer, 1, file_size, file); // No check if fread actually read file_size bytes
    buffer[file_size] = '\0'; // Null termination without validating fread success

    fclose(file);
    // "output" is supposed to hold a copy of buffer, but it is not assigned
    // Missing: *output = buffer;
    
    // Memory allocated for buffer is not freed on all code paths
    return 0; 
}