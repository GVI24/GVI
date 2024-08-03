static void to_uppercase(char *text, int text_length) {
    int i;
    // Vulnerability: No bounds checking on text based on text_length
    for (i = 0; i < text_length; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] -= 'a' - 'A'; // Potential out-of-bounds write if text_length is incorrect
        }
    }
}