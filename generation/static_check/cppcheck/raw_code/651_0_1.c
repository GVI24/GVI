#define BUFFER_SIZE 256
void process_user_data(FILE *file) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE * 2, file); // Overflows buffer
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Potential out-of-bounds write
        printf("Data: %s\n", buffer);
    }
}

