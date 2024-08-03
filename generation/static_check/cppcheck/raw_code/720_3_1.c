static void LoadResource(char *resourceBuffer, int resourceSize, const char *sourceBuffer) {
    if (resourceBuffer != NULL && sourceBuffer != NULL) {
        // Assuming resourceBuffer can hold resourceSize bytes.
        
        // Improper use of memcpy can cause buffer overflow if sourceBuffer is larger than resourceSize.
        memcpy(resourceBuffer, sourceBuffer, strlen(sourceBuffer)); // Potential buffer overflow
        
        // Resource data has been copied to resourceBuffer...
    }
}