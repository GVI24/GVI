#define MAX_PREFIX_SIZE 50

void print_status(char *status, char *prefix) {
    char log_entry[256];
    int prefix_len = strlen(prefix);
    
    if (prefix_len > MAX_PREFIX_SIZE) {
        printf("Error: Prefix too long.\n");
        return;
    }
    
    // Vulnerable: If combined length of prefix and status exceeds 256 chars, it will overflow buffer.
    sprintf(log_entry, "%s - %s", prefix, status);
    
    puts(log_entry);
}