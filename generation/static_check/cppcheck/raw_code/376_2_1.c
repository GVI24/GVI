static void spi_flash_load(SPIFlashState *flash_state) {
    int local_buffer[SPI_FLASH_SIZE];
    int read_bytes = flash_state->transfer_size;
    
    if (read_bytes > SPI_FLASH_SIZE) {
        read_bytes = 0; // Faulty attempt to avoid overflow
    }
    
    for (int i = 0; i < read_bytes; i++) {
        local_buffer[i] = flash_state->buffer[i + flash_state->read_offset];
    }
    
    memcpy(flash_state->buffer, local_buffer, read_bytes); // Potential overflow
    flash_state->write_offset = read_bytes;
}

