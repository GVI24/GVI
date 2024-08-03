void constructFilePath(char *dest, const char *folder, const char *file) {
    strcpy(dest, folder);  // Assume 'dest' is large enough
    strcat(dest, "/");     // No bounds checking
    strcat(dest, file);    // No bounds checking
}

