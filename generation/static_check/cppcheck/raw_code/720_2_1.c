static void CreateStatusMessage(char *statusBuffer, int bufferSize, int statusCode) {
    if (statusBuffer != NULL) {
        char statusMessage[64];
        sprintf(statusMessage, "Status Code: %d, Description: %s", statusCode, "Operation completed successfully."); // Potential buffer overflow
        
        strncpy(statusBuffer, statusMessage, bufferSize - 1);
        statusBuffer[bufferSize - 1] = '\0'; // Null-terminate to prevent buffer overflow from strncpy.
        
        // Status message is now prepared...
    }
}

