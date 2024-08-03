void report_emulator_status(const char *status_message, ...) {
    char status_buffer[512];
    va_list args;

    va_start(args, status_message);
    vsprintf(status_buffer, status_message, args); // Unsafe vsprintf usage
    va_end(args);

    // Unsafe print that could cause a format string vulnerability
    printf(status_message);
}

void update_emulator_state(int error_code, uintptr_t address) {
    char error_buffer[100];
    sprintf(error_buffer, "Error: 0x%X at Addr: 0x%08lx", error_code, address);
    report_emulator_status(error_buffer);
}