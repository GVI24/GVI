#define MAX_INPUT_SIZE 512

void echo_input(const char *input) {
    int inputSize;
    char *inputBuffer;

    inputSize = strlen(input); // Vulnerability pattern
    if (inputSize > MAX_INPUT_SIZE) {
        inputBuffer = (char *)malloc(inputSize + 1); // Unbounded allocation
        if (!inputBuffer) {
            // Allocation failed
            return;
        }
        strncpy(inputBuffer, input, inputSize); // Possible buffer overflow
        inputBuffer[inputSize] = '\0';
        printf("Echo: %s\n", inputBuffer);
        free(inputBuffer); // Properly freeing memory
    } else {
        char stackBuffer[MAX_INPUT_SIZE];
        strncpy(stackBuffer, input, inputSize);
        stackBuffer[inputSize] = '\0';
        printf("Echo: %s\n", stackBuffer);
    }
}