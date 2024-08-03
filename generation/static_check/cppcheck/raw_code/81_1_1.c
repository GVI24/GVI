static int read_data_chunks(FILE *dataFile, int skipWhitespace) {
    char line[256];
    int result = 0;
    while (!feof(dataFile)) {
        if (fgets(line, sizeof(line), dataFile) == NULL) {
            continue; // Infinite loop if feof() is never true or fgets fails consistently
        }
        if (skipWhitespace && is_whitespace_line(line)) {
            continue; // Risk of infinite loop with files having only whitespace lines
        }
        result = process_chunk(line);
        if (result != 1) {
            break; // Break condition
        }
    }
    return result;
}