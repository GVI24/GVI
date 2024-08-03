#define BUFFER_SIZE 32

int store_user_input(char *user_input) {
    char buffer[BUFFER_SIZE];

    // Vulnerability: The buffer can be overflowed if user_input is larger than BUFFER_SIZE.
    strcpy(buffer, user_input);

    // Do something with the buffer here
    if (buffer[0] == '\0') {
        FATAL_ERROR("User input is empty.");
    }

    printf("User Input: %s\n", buffer);
    return 1;
}