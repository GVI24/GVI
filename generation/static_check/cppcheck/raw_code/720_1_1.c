static void AppendPath(char *baseDir, const char *subDir) {
    if (baseDir != NULL && subDir != NULL) {
        strcat(baseDir, "/"); // Potential buffer overflow if baseDir is not large enough
        strcat(baseDir, subDir); // Potential buffer overflow if baseDir is not large enough
        
        // Now baseDir contains the full path to the sub directory...
    }
}

