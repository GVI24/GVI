void my_strcat(char *dest, const char *src, int max_dest_size) {
    while (*dest) dest++; // Find the end of 'dest'
    while (*src && max_dest_size--) { // max_dest_size is not checked appropriately, can lead to 'dest' overflow
        *dest++ = *src++;
    }
    *dest = '\0';
}

