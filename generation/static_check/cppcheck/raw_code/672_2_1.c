void processInput(char *data) {
    char *buffer = malloc(strlen(data) + 1);
    strcpy(buffer, data);
    // Some processing code here
    free(buffer);
    // Accidental use of buffer after it was free'd
    printf("Last input was: %s\n", buffer);  // Use after free vulnerability
}

