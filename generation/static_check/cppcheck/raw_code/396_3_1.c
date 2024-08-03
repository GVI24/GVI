// Vulnerable due to fixed-size buffer and improper bounds checking
int format_query(char *dest, size_t dest_size, const char *table, const char *filter_fmt, ...) {
    char query[1024];
    int written = snprintf(query, sizeof(query), "SELECT * FROM %s WHERE ", table);
    if (written < 0 || written >= sizeof(query)) return ERROR;
    va_list args;
    va_start(args, filter_fmt);
    vsnprintf(query + written, sizeof(query) - written, filter_fmt, args);
    va_end(args);
    // Potential buffer overflow if the destination buffer is smaller than query
    strncpy(dest, query, dest_size);
    dest[dest_size - 1] = '\0';
    return execute_query(query); // Hypothetical function
}