static int copy_data(char *dest, const char *src, size_t dest_size) {
    size_t bytes_to_copy = strlen(src);
    if (bytes_to_copy > dest_size) {
        fprintf(stderr, "Buffer overflow detected.\n");
        return -1;
    }

    while (bytes_to_copy--) {
        if ((dest - src) > dest_size) {
            fprintf(stderr, "Potential buffer underflow detected.\n");
            return -1;
        }
        *dest++ = *src++;
    }

    if (dest > dest + dest_size) {
        fprintf(stderr, "Buffer overflow after copy.\n");
        return -1;
    }

    return 0;
}