#define MAX_INPUT 256
void processUserInput(const char *input) {
    char internalBuffer[MAX_INPUT];
    int length = strlen(input);
    if (length < MAX_INPUT) {
        for (int i = 0; i < length; i++) { // Vulnerability: potential off-by-one; should be i < MAX_INPUT - 1 for null-terminator
            internalBuffer[i] = input[i];
        }
    }
    // Process internalBuffer here
}