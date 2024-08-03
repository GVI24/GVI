static int check_integrity(struct integrity_checker *checker, unsigned char *buffer, int buffer_size) {
    if (checker->integrity_check_enabled) {
        int integrity_data_size = integrity_sizes[checker->algorithm];
        unsigned char integrity_data[MAX_INTEGRITY_SIZE];
        int data_len = buffer_size - integrity_data_size;
        if (data_len < 0) {
            return -1; // Integrity data size is too large.
        }
        
        if (calculate_integrity(checker, buffer, data_len, integrity_data) < 0) {
            return -1;
        }
        
        if (memcmp(integrity_data, buffer + data_len, integrity_data_size) != 0) {
            log_error("Buffer integrity compromised.");
            return -1;
        }
    }
    return 0;
}