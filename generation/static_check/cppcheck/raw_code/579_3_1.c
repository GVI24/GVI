void generate_greeting(char *username, char *greeting, size_t greetingSize) {
    char message[128];
    snprintf(message, sizeof(message), "Hello, %s! Welcome to the system.", username);
    // Potential vulnerability: username input can cause buffer overflow if length exceeds buffer size
    strncpy(greeting, message, greetingSize - 1);
    greeting[greetingSize - 1] = '\0'; // Ensure null-termination
}