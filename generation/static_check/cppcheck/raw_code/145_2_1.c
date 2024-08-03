static int copyExternalData(char *source, size_t dataSize) {
    char localBuffer[100];
    if (dataSize > sizeof(localBuffer)) { // Vulnerable: Should be compared before copying
        handle_error();
        return -1;
    }
    memcpy(localBuffer, source, dataSize); // Potential buffer overflow if dataSize is not properly validated
    printf("%s\n", localBuffer); // Assuming null-terminated data for printing
    return 0;
}

