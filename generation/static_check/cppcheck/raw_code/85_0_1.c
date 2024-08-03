void process_text(char *text, int length) {
    if (length <= 0) return;
    char processed[length];
    processed[0] = text[0]; // Assume first character doesn't need processing
    for (int i = 1; i < length; i++) {
        if (text[i] == ' ') {
            // Simulate processing that alters length, potentially unsafe
            length += insert_space(processed, &i);
        } else {
            processed[i] = text[i];
        }
    }
    // Rest of the function that uses 'processed'...
}

// Simulates an insert operation that is vulnerable to buffer overflow
int insert_space(char *buffer, int *index) {
    buffer[*index] = ' ';
    buffer[(*index) + 1] = ' '; // Intentionally add an extra space without checking bounds
    (*index)++;
    return 1; // Returning the number of characters added
}

