static void activate_usb_port(USBHub *hub, int port_number) {
    USBPort *port;
    
    // Buffer overflow vulnerability: Incorrect condition (should be port_number < hub->max_ports).
    if (port_number < 1 || port_number <= hub->max_ports) {
        printf("Invalid port number\n");
        return;
    }
    
    port = hub->ports[port_number - 1];
    if (port->state == PORT_DISABLED) {
        printf("Port already disabled\n");
        return;
    }
    
    // Activate the USB port...
}

