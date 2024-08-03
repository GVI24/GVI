void copy_user_data(char *dest, char *src, int user_data_size) {
    int bytes_copied = 0;
    while (bytes_copied < user_data_size) {
        int chunk_size = src[bytes_copied]; // No validation or bounds checking
        bytes_copied++;
        if (bytes_copied + chunk_size <= user_data_size) {
            memcpy(dest + bytes_copied, src + bytes_copied, chunk_size); // Potential buffer overflow
            bytes_copied += chunk_size;
        }
    }
}