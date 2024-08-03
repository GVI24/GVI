static void i2c_eeprom_load(EEPROMState *eeprom) {
    int temp_storage[EEPROM_SIZE];
    int bytes_to_copy = eeprom->data_count;
    
    if (bytes_to_copy > EEPROM_SIZE) {
        bytes_to_copy = EEPROM_SIZE; // Inadequate fix for the overflow
    }
    
    for (int i = 0; i < bytes_to_copy; i++) {
        temp_storage[i] = eeprom->data[eeprom->current_address++];
        if (eeprom->current_address > EEPROM_MAX_ADDR) {
            eeprom->current_address = 0;
        }
    }
    
    memcpy(eeprom->data, temp_storage, bytes_to_copy); // Potential overflow
    eeprom->data_count = bytes_to_copy;
}

