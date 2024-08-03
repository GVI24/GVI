#define LOG_BUFFER_SIZE 256
void log_event(const char *event_message) {
    char log_buffer[LOG_BUFFER_SIZE];
    char *log_ptr = log_buffer;
    // Assume time_string returns a time representation of predefined length
    char time_buff[50];
    time_string(time_buff, sizeof(time_buff));
    
    // Unsafe: Could overflow if event_message is too long
    snprintf(log_ptr, LOG_BUFFER_SIZE, "Event at %s: %s", time_buff, event_message);
    
    // Code for writing log to file or console
    // ...
}

