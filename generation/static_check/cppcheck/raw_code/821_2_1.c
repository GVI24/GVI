#define BUFFER_SIZE 256

void read_file_to_buffer(const char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "r");

    // Vulnerability: No checks on the length of the file being read
    if (file) {
        while (!feof(file)) {
            // Vulnerability: fgets may write beyond buffer if line is too long
            fgets(buffer, sizeof(buffer), file);
            // ... Process buffer
        }
        fclose(file);
    }
}