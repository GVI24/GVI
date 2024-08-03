static void convertPathToUnixStyle(char *path) {
    char *p;
    // Assuming UNIX uses '/' as the path separator
    while ((p = strchr(path, '\\')) != NULL) {
        *p = '/';
    }
}

