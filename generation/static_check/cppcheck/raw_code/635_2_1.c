void log_activity(const char *userInput) {
    // Format string vulnerability as userInput is directly passed to printf
    printf(userInput);
    // ... Additional logic ...
}

