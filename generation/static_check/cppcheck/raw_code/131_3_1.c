void logMessage(const char* message) {
    char logEntry[1024]; // fixed-size buffer
    time_t currentTime = time(NULL);
    char* timeStr = ctime(&currentTime); // get a string representation of the current time
    snprintf(logEntry, sizeof(logEntry), "[%s]: %s\n", timeStr, message); // potentially vulnerable snprintf
    // ... (the rest of the function would write 'logEntry' to a log file or stdout)
}