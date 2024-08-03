#define BUFFER_SIZE 256
void copy_input_to_buffer(char *input) {
    char buffer[BUFFER_SIZE];
    int index = 0;
    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        buffer[index++] = ch; // Potential buffer overflow
    }
    buffer[index] = '\0'; // Null-terminate string
}

