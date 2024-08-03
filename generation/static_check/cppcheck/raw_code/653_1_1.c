void copy_and_process(char *src, int src_len, char *dest, int dest_len) {
    int i = 0;
    while (i < src_len) {
        // Vulnerability: No check to ensure dest has enough space
        dest[i] = src[i] ^ 0x20; // Toggle case assuming ASCII letters
        i++;
    }

    if (i >= dest_len) {
        // This check should prevent the overflow, but it's done too late
        fprintf(stderr, "Destination buffer is too small!\n");
        exit(EXIT_FAILURE);
    }
}