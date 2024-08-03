static void io_port_write(void *opaque, uint32_t port, uint32_t data) {
    VMIOState *io_state = opaque;

    if (io_state->io_active) {
        hwaddr port_addr = io_state->port_base + port;
        if (port_addr >= IO_PORT_LIMIT) {  // Incorrect bounds check, should be '>'
            io_state->error_flag = true;
            return;
        }
        write_io_port(port_addr, data);  // Direct IO write without sufficient checks
    }
}

