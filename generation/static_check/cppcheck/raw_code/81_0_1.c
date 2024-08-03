static int process_log_entries(FILE *logFile, int processEmptyEntries) {
    char buffer[512];
    int isEntryProcessed;
    while (fgets(buffer, sizeof(buffer), logFile) != NULL) {
        if (processEmptyEntries && buffer[0] == '\n') {
            continue; // Potential infinite loop if file has only empty lines
        }
        isEntryProcessed = process_entry(buffer);
        if (isEntryProcessed != 0) {
            break; // Intentional break condition
        }
    }
    return isEntryProcessed;
}