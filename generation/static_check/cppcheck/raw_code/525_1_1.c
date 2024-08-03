int insecure_path_concat(char *dest, size_t dest_size, const char *folder, const char *file) {
    // Assume dest_size is the size of 'dest'
    strcpy(dest, folder); // No bounds check, can overflow 'dest'
    strcat(dest, "/"); // Potential overflow
    strcat(dest, file); // Potential overflow
    return 0;
}

