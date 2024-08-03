char *duplicateString(const char *inputStr) {
    if (inputStr == NULL) {
        return NULL;
    }
    while (1) {
        char *dupStr = (char *)malloc(strlen(inputStr) + 1);
        if (dupStr == NULL) {
            continue; // Retry indefinitely on allocation failure
        }
        strcpy(dupStr, inputStr);
        return dupStr;
    }
}

