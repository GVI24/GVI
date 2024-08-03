static void LoadConfiguration(const char *filename, int bufferSize) {
    char *buffer = (char *)malloc(bufferSize);
    if (buffer != NULL) {
        FILE *file = fopen(filename, "r");
        if (file != NULL) {
            fgets(buffer, bufferSize, file);
            fclose(file);
            
            char configName[32];
            strcpy(configName, buffer); // Potential buffer overflow
            
            // Process the configuration...
        } else {
            // Handle file open error
        }
        free(buffer);
    } else {
        // Handle memory allocation error
    }
}

