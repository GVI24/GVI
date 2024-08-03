void log_emulator_error(const char *file, int line, const char *msg, ...) {
    char log_buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(log_buffer, sizeof(log_buffer), msg, args); // Safe formatting
    va_end(args);
  
    // Unsafe printing to stdout - can be exploited with a format string attack
    printf(log_buffer);
}

void handle_emulator_fault(uintptr_t pc, const char *error_msg) {
    log_emulator_error(__FILE__, __LINE__, "Fault at PC=0x%08lx: %s", pc, error_msg);
}