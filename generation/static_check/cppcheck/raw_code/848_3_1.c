void calculate_checksum(DATA_BLOCK *data_block, int num_entries) {
    int checksum = 0;
    for (int i = 0; i < num_entries * 2; i++) { // Potential arithmetic overflow in multiplication
        checksum += data_block->entries[i]; // Possible out-of-bounds access if overflow occurs
    }
    data_block->checksum = checksum;
}