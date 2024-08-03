void read_user_data(char *buffer, int len) {
    // ... some code to read data from an I/O source ...

    // Vulnerable: No check to ensure 'len' is less than the size of 'buffer'
    memcpy(buffer, some_data_source, len);
    
    // ... additional logic ...
}

