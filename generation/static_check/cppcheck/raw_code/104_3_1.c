void log_encoding_parameters(MpegEncContext *ctx, char *log_message) {
    // Vulnerability: Using log_message directly in printf without format
    // can lead to format string vulnerabilities if log_message is user-controlled
    printf(log_message);
    
    // Correct way would be printf("%s", log_message);
}

// Usage Example:
// MpegEncContext context;
// log_encoding_parameters(&context, "Frame size: %d x %d"); // Unsafe, could lead to arbitrary code execution