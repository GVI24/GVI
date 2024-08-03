// Vulnerable due to sprintf without bounds checking
int log_message(int priority, const char *message, ...) {
    char log_entry[MAX_LOG_MESSAGE_LENGTH];
    va_list args;
    va_start(args, message);
    sprintf(log_entry, "[%lu] [Priority: %d] ", (unsigned long)time(NULL), priority);
    vsprintf(log_entry + strlen(log_entry), message, args);
    va_end(args);
    // Log the entry (hypothetical function)
    return write_log_to_file(log_entry);
}
