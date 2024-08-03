void manipulate_string(char *str, int buf_size) {
    int i = 0;
    while (str[i] != '\0' && i < buf_size) {
        if (str[i] == '-') {
            expand_dash(str, &i, buf_size); // Potentially overflow 'str'
        }
        i++;
    }
    // Rest of the function...
}

void expand_dash(char *str, int *index, int buf_size) {
    if (*index < buf_size - 2) { // Off-by-one error, doesn't check for enough space
        for (int i = buf_size - 3; i >= *index; i--) {
            str[i + 2] = str[i]; // Shift characters to make room for expansion
        }
        str[(*index)++] = ' ';
        str[*index] = ' '; // Inserts two spaces, not considering '\0'
    }
}

