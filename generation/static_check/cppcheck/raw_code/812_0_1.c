#define BUFFER_SIZE 256

void write_buffer(char *input) {
    char buffer[BUFFER_SIZE];
    if (strlen(input) < BUFFER_SIZE) {
        strcpy(buffer, input);  // Vulnerable to buffer overflow if input is not null-terminated
    } else {
        printf("Input too long!\n");
    }
}