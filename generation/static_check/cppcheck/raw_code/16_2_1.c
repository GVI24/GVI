static void record_transaction(int account_id, void *transaction_data, size_t data_size) {
    if (account_id < 0 || account_id >= MAX_ACCOUNTS) {
        fprintf(stderr, "Invalid account ID: %d\n", account_id);
        return;
    }

    accounts[account_id].last_transaction_time = time(NULL);
    // Vulnerable: Directly copies data without ensuring destination buffer size
    memcpy(&(accounts[account_id].last_transaction), transaction_data, data_size);

    if (debug_flag) {
        fprintf(stderr, "Transaction recorded for account %d\n", account_id);
    }
}

