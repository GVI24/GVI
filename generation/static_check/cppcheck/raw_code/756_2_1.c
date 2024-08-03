void copy_strings(char **dest, char **src, int count) {
    for (int i = 0; i < count; i++) {
        // Vulnerable: No bounds checking on string lengths
        strcpy(dest[i], src[i]);
    }
}