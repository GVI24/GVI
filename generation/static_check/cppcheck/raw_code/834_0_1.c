void reverse_string(char *str, int length) {
    char reversed[64]; // Fixed size buffer
    int index = 0;

    // Reverse the string into 'reversed' buffer without checking bounds
    for (int i = length - 1; i >= 0; --i) {
        reversed[index++] = str[i];
    }
    reversed[index] = '\0'; // Potential out-of-bounds write here

    // Copy the reversed string back to the input string
    for (int i = 0; i <= length; ++i) {
        str[i] = reversed[i]; // Potential out-of-bounds read here
    }
}

