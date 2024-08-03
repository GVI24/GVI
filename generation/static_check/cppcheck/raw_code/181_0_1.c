static void session_register_data(int session_id, const unsigned char *data, size_t data_len) {
    unsigned char *session_data;
    session_data = malloc(data_len);
    if (session_data) {
        memcpy(session_data, data, data_len);
    }
    
    // ... Some processing with session_data ...
    
    if (session_lookup(session_id)) {
        // Update session info, but forgot to free previous session_data
    } else {
        // session_data is not stored or freed
    }
    
    // Missing free for session_data
}

