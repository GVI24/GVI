typedef struct {
    char key[256];
    char value[256];
} ConfigEntry;

void ParseConfig(char *configLine, ConfigEntry *entry) {
    char *token = strtok(configLine, "=");
    // Vulnerability: No NULL check after strtok
    strcpy(entry->key, token); // Vulnerability: No boundary check
    token = strtok(NULL, "=");
    // Vulnerability: No NULL check after strtok
    strcpy(entry->value, token); // Vulnerability: No boundary check
    // Vulnerability: No check for token count; assumes always 2 tokens
}