#define MAX_LINE_LENGTH 512
void read_line_unsafe(FILE *file) {
    char line[MAX_LINE_LENGTH];
    int i = 0;
    int ch;

    while ((ch = fgetc(file)) != '\n' && ch != EOF) {
        line[i++] = (char)ch; // No bounds checking, can cause buffer overflow
    }
    line[i] = '\0';
}

