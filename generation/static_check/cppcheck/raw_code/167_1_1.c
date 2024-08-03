void user_input_echo(char *input) {
    char echo_buffer[100];
    
    // Vulnerability: No check for the length of the input, leading to a possible buffer overflow.
    sprintf(echo_buffer, "You entered: %s", input);
    
    printf("%s\n", echo_buffer);
}