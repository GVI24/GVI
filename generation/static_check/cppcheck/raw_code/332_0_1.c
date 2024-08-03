static int extract_command_code (char *cmd_buffer, int index, int *cmd_code) {
    int buffer_len = strlen(cmd_buffer);
    if (index < 0 || index >= buffer_len) {
        // Handle error: index out of bounds
        return -1;
    }

    *cmd_code = cmd_buffer[index];
    int next_byte = cmd_buffer[index + 1];  // Potential out-of-bounds read
    *cmd_code |= (next_byte << 8);

    return index + 2;
}
