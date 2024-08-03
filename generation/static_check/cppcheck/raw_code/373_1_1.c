void unsafe_str_append(char *dest, int dest_size, const char *src) {
    int dest_len = strlen(dest);
    int src_len = strlen(src);

    if (dest_len + src_len >= dest_size) {
        int new_size = dest_len + src_len + 1;
        int scale = dest_size * 2;

        new_size = new_size + (scale - new_size % scale); // Potential integer overflow
        dest = realloc(dest, new_size);
        
        if (!dest) {
            // Failed to reallocate memory
            return;
        }
    }

    strcat(dest, src); // Unsafe if src is not null-terminated within src_len
}