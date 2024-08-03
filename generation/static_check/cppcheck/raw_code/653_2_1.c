#define BUFFER_SIZE 256

void unsafe_string_copy(char *source) {
    char localBuffer[BUFFER_SIZE];

    // Buffer overflow if source is longer than BUFFER_SIZE
    strcpy(localBuffer, source);
    printf("Copied string: %s\n", localBuffer);
}