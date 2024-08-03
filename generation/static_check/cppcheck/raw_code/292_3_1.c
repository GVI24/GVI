static uint32_t execute_driver_command(void *driver_state, hwaddr command_addr, unsigned command_size) {
    DriverState *d_state = driver_state;
    uint32_t command_id = command_addr >> 2;
    if (command_id >= DRIVER_COMMAND_LIMIT) {
        return 0;
    }
    if (d_state->command_funcs[command_id]) {
        return d_state->command_funcs[command_id](d_state->command_context[command_id], command_addr);
    }
    return 0;
}