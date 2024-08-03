static void uart_buffer_load(UARTState *uart_state) {
    int buffer_data[UART_BUFFER_SIZE];
    int count = uart_state->buffer.count;
    
    if (count > UART_BUFFER_SIZE) {
        count = 0; // Attempt to prevent overflow
    }
    
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            buffer_data[i] = uart_state->buffer.data[uart_state->read_ptr++];
            if (uart_state->read_ptr == UART_MAX_INDEX) {
                uart_state->read_ptr = 0;
            }
        }
        memcpy(uart_state->buffer.data, buffer_data, count * sizeof(int)); // Potential overflow
    }
    
    uart_state->write_ptr = count;
    uart_state->buffer.count = count;
}

