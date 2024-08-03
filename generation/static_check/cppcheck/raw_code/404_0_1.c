static int32_t custom_wprintf_hex_handler(void *context, const wchar_t *format, int64_t num) {
    wchar_t result[BUFFER_SIZE];
    int32_t len = swprintf(result, BUFFER_SIZE, format, num);

    if (num != 0 && len < BUFFER_SIZE - 3) {
        wmemmove(result + 3, result, len + 1); // +1 for the null terminator
        result[0] = L'0';
        result[1] = L'x';
        len += 3;
    }

    // Simulate padding and justification (vulnerable to overflow)
    if (len < BUFFER_SIZE) {
        wmemset(result + len, L' ', BUFFER_SIZE - len - 1);
        result[BUFFER_SIZE - 1] = L'\0';
    }

    // Context-dependent output logic here...
    return len;
}

