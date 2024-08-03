void tokenizeInput(char *input) {
    char *tokens[10]; // Fixed size array of pointers
    int tokenCount = 0;
    char *token = strtok(input, ",");
    while (token != NULL) {
        tokens[tokenCount] = token; // Vulnerability: no bounds checking for 'tokens' array
        tokenCount++;
        token = strtok(NULL, ",");
    }
}

// Note: These examples are intentionally flawed to demonstrate the vulnerability pattern
// and should not be used in any real-world software without proper bounds checking and validation.