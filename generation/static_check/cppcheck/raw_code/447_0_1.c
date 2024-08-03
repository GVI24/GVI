#define BUFFER_SIZE 256

void copy_input(char *userInput) {
    char buffer[BUFFER_SIZE];
    int bufferSize;

    bufferSize = strlen(userInput) + 1; // Vulnerability pattern
    if (bufferSize > BUFFER_SIZE) {
        char *dynamicBuffer = (char *)malloc(bufferSize); // Unbounded allocation
        if (dynamicBuffer == NULL) {
            // Handle error
            return;
        }
        strcpy(dynamicBuffer, userInput); // Possible buffer overflow
        printf("Input: %s\n", dynamicBuffer);
        free(dynamicBuffer);
    } else {
        strcpy(buffer, userInput); // Safe copy
        printf("Input: %s\n", buffer);
    }
}