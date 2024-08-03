// Vulnerable Function Example 3
int file_to_buffer(const char *filename, char *buffer, size_t max_size) {
    FILE *file = fopen(filename, "rb");
    if (!file || !buffer) {
        return -1;
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    if (file_size > max_size) { // Potential integer overflow and consequent buffer overflow
        fclose(file);
        return -1;
    }
    fread(buffer, 1, file_size, file); // Assuming buffer is large enough without checking
    fclose(file);
    return 0;
}