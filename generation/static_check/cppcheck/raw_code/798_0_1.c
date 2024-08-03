#define BUFFER_SIZE 256

int read_line_from_file(FILE *file) {
    char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, file) == NULL) {
        // Handle error or EOF
        return -1;
    }
    // Process the buffer here, which could lead to overflow if not careful
    printf("%s", buffer);
    // ... Do something with the buffer
    return 0;
}