#define BUFFER_SIZE 256

void log_message(char *message) {
    char buffer[BUFFER_SIZE];
    int message_len = strlen(message);
    
    if (message_len >= BUFFER_SIZE) {
        printf("Error: Message too long to log.\n");
        return;
    }
    
    // Vulnerable to buffer overflow if message contains more than BUFFER_SIZE characters
    strcpy(buffer, message); 
    
    // Simulated logging action
    printf("LOG: %s\n", buffer);
}