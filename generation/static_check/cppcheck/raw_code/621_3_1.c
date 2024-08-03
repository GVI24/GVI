void free_resources(int *buffer1, int *buffer2) {
    if (buffer1 != NULL) {
        free(buffer1);
    }
    if (buffer2 != NULL) {
        free(buffer2);
    }
    // Later in the code, mistakenly attempting to free buffer1 again.
    if (buffer1 != NULL) {
        free(buffer1); // Double free vulnerability.
    }
}