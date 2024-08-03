int findCharInString(char *string, char target) {
    int i = 0;
    while (string[i] != '\0') { // Vulnerability: No bound check, can go past the buffer if target is not in string
        if (string[i] == target) {
            return i;
        }
        i++;
    }
    return -1; // Target not found
}

