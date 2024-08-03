// Vulnerable Function Example 4
void user_data_process(char *user_input, size_t length, void (*process_func)(char *)) {
    if (!user_input || length == 0 || !process_func) {
        return;
    }
    char stack_buffer[256];
    if (length > sizeof(stack_buffer)) {
        // No alternate path if length exceeds stack_buffer size, leading to buffer overflow
        return;
    }
    memcpy(stack_buffer, user_input, length); // Potential buffer overflow if improper length
    process_func(stack_buffer);
}