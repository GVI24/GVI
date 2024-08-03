static int32_t unsafe_string_formatter(void *context, char *dest, size_t dest_size, const char *format, int32_t value) {
    char buffer[BUFFER_SIZE];
    int len = snprintf(buffer, BUFFER_SIZE, format, value);

    if (buffer[0] != '-' && len < BUFFER_SIZE - 1) {
        memmove(buffer + 1, buffer, len + 1); // Shift the string to add padding
        buffer[0] = ' ';
        len++;
    }

    strncpy(dest, buffer, dest_size); // No guarantee that dest can hold BUFFER_SIZE

    // Padding and justification code here...
    return len;
}

