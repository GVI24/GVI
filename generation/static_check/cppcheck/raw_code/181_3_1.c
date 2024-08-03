static void store_transaction_data(int transaction_id, const unsigned char *trans_data, size_t trans_data_size) {
    unsigned char *transaction_buffer;
    transaction_buffer = (unsigned char *)calloc(trans_data_size, sizeof(unsigned char));
    if (transaction_buffer) {
        memcpy(transaction_buffer, trans_data, trans_data_size);
    } else {
        return; // Allocation failed, return, but this branch is unnecessary since calloc will return NULL which is handled
    }

    // ... Some processing with transaction_buffer ...
    
    if (transaction_exists(transaction_id)) {
        // Attempt to update transaction, but don't free old transaction_buffer
    } else {
        // New transaction, but transaction_buffer is not added to any data structure and not freed
    }

    // Missing free for transaction_buffer
}